#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 8e5+1, oo = 1e9;

struct SAT {
    // Variable i, 2*i+1 = p_i and 2*i is ~p_i
    int n;  // Number of nodes in the implication graph
    // n/2 is number of variables
    vector<basic_string<int>> adj, rev;
    vector<int> order,comp;
    bitset<mxN> visited;
    vector<bool> assignment;
    void OR(int a, int b) {
        adj[a^1].push_back(b);
        adj[b^1].push_back(a);
        rev[b].push_back(a^1);
        rev[a].push_back(b^1);
    }
    void XOR(int a, int b) {
        OR(a,b);
        OR(a^1,b^1);
    }
    void good(int a,int b, bitset<4> mask) {
        if(mask.count()==15) return;
        if(mask==0) {
            cout << "NO\n";
            exit(0);
        } else if(mask.count()==1) {
            int g = mask._Find_first();
            int aa = g/2, bb = g%2;
            OR(a^aa,a^aa),OR(b^bb,b^bb);
        } else if(mask==3) {
            OR(a,a);
        } else if(mask==5) {
            OR(b,b);
        } else if(mask==6) {
            XOR(a,b);
        } else if(mask==7) {
            OR(a,b);
        } else if(mask==9) {
            XOR(a^1,b);
        } else if(mask==10) {
            OR(b^1,b^1);
        } else if(mask==11) {
            OR(a,b^1);
        } else if(mask==12) {
            OR(a^1,a^1);
        } else if(mask==13) {
            OR(a^1,b);
        } else if(mask==14) {
            OR(a^1,b^1);
        }
    }
    SAT (int k){
        n=k;
        adj.resize(n);
        rev.resize(n);
    }
    void dfs1(int at) {
        visited[at] = true;
         for(its[at]=adj[at].begin();its[at]!=adj[at].end();++its[at]) {
            if (!visited[*its[at]]) dfs1(*its[at]);
        }
        order.push_back(at);
    }
    int c=0;
    vector<basic_string<int>::iterator> its;
    void dfs2(int at) {
        visited[at] = true;
        comp[at]= c;
        for(its[at]=rev[at].begin();its[at]!=rev[at].end();++its[at]) {
            if (!visited[*its[at]]) dfs2(*its[at]);
        }
    }
    bool solve() {
        assignment.resize(n/2);
        comp.resize(n);
        its.resize(n);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs1(i);
        }
        int id = n;
        visited.reset();
        for (int i = n - 1; i >= 0; --i) {
            int at = order[i];
            if (!visited[at]) {
                c = --id;
                dfs2(at);
            }
        }

        for(int i=0;i<n/2;++i) {
            if(comp[2*i] == comp[2*i+1]) return false;
            assignment[i] = comp[i*2] > comp[i*2+1];
        }
        return true;
    }
};
vector<basic_string<int>> adj;
vi par,d;
void dfs(int at) {
    for(auto to : adj[at]) if(to!=par[at]) {
        par[to]=at;
        d[to]=d[at]+1;
        dfs(to);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    SAT sat(q*2);
    adj.resize(n);
    par.resize(n,-1);
    d.resize(n);
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    vector<array<char,2>> chs(n,{'?','?'});
    vi from(n,-1);
    vector<bitset<4>> pos(q,15);
    for(int id=0;id<q;++id) {
        int u,v; cin >> u >> v;
        --u,--v;
        string s;
        cin >> s;
        // get the path
        if(d[u]<d[v]) swap(u,v),reverse(all(s));
        vi pu,pv;
        while(d[u]>d[v]) {
            pu.push_back(u);
            u=par[u];
        }
        while(u!=v) {
            pu.push_back(u);
            pv.push_back(v);
            u=par[u];
            v=par[v];
        }
        pu.push_back(u);
        reverse(all(pv));
        pu.insert(pu.end(),all(pv));
        int len = s.size();
        // assert(len==pu.size());
        vi h;
        for(int i=0;i<len;++i) {
            auto at = pu[i];
            array<char,2> cs = {s[i],s[len-1-i]};
            auto& f = from[at];
            if(f!=-1) {
                
                bitset<4> mymask = {};
                for(int j=0;j<2;++j) for(int k=0;k<2;++k) {
                    mymask[j+k*2] = cs[j]==chs[at][k];
                }
                bool before = pos[f]==15;
                pos[f]&=mymask;
                if(before and pos[f]!=15) h.push_back(f);
            }
            f = id;
            chs[at] = cs;
        }
        for(auto f : h) {
            auto& bs = pos[f];
            sat.good(f*2,id*2,bs);
            bs = 15;
        }
    }
    if(!sat.solve()) {
        cout << "NO\n";
        exit(0);
    }
    cout << "YES\n";
    string res(n,'z');
    for(int i=0;i<n;++i) {
        auto f = from[i];
        if(f!=-1) {
            res[i] = chs[i][sat.assignment[f]];
        }
    }
    cout << res;
}