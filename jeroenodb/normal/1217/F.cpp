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
const int mxN = 2.1e5+10, oo = 1e9;
const int B=201;
int szpar[mxN];
struct DSU{
    DSU(int n) {
        fill(szpar,szpar+mxN,-1);
    }
    void link(int a, int b) {
        if(szpar[a]>szpar[b]) {
            swap(a,b);
        }
        szpar[a] +=szpar[b];
        szpar[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(szpar[a]<0) return a;
        return szpar[a] = find(szpar[a]);
    }
};
bitset<mxN*2> active;
bitset<mxN> vis;
vector<pi> es;
vi adj[mxN];
struct Special {
    bitset<mxN*2> s;
    vi activeE, activeV;
    void add(int i) {
        if(s[i]) return;
        s[i]=true;
        activeE.push_back(i);
    }
    void resetvis() {
        for(auto& i : activeV) {
            vis[i]=false;
        }
    }
    void reset() {
        resetvis();
        for(auto i : activeV) {
            adj[i].clear();
        }
        for(auto& i : activeE) {
            s[i]=false;
        }
        activeE.clear(),activeV.clear();
    }
} special;


typedef array<int,3> query;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<query> qs(m);

    {
    map<pi,int> emap;
    auto id = [&](pi p) {
        if(p.first>p.second) swap(p.first,p.second);
        if(emap.count(p)) return emap[p];
        es.push_back(p);
        return emap[p]=es.size()-1;
    };
    for(auto& [t,x,y] : qs) {
        cin >> t >> x >> y,--x,--y;
        if(t==2) continue;
        int a = id(pi{x,y});
        int b = id(pi{(x+1)%n,(y+1)%n});
        x=a,y=b;
    }
    }
    bool last=0;
    vector<bool> ans;
    for(int i=0;i<m;i+=B) {
        int l=i,r=min(m,i+B);
        DSU dsu(n);
        special.reset();
        for(int j=l;j<r;++j) {
            auto [t,x,y] = qs[j];
            if(t==2) continue;
            special.add(x);
            special.add(y);
        }
        for(int j=0;j<es.size();++j) {
            if(active[j] and !special.s[j]) {
                auto [x,y] = es[j];
                dsu.unite(x,y);
            }
        }
        for(int j : special.activeE) {
            auto [x,y] = es[j];
            x=dsu.find(x),y=dsu.find(y);
            adj[x].push_back(j);
            adj[y].push_back(j);
            if(!vis[x]) {
                special.activeV.push_back(x);
                vis[x]=true;
            }
            if(!vis[y]) {
                special.activeV.push_back(y);
                vis[y]=true;
            }
        }
        // do queries
        for(int j=l;j<r;++j) {
            auto [t,x,y] = qs[j];
            if(t==1) {
                if(last) active[y].flip();
                else active[x].flip();
            } else {
                // do a DFS
                if(last) x=(x+1)%n, y=(y+1)%n;
                x=dsu.find(x), y = dsu.find(y);
                stack<int> st;
                st.push(x);
                special.resetvis();
                vis[x]=true;
                bool found=false;

                while(!st.empty()) {
                    int at = st.top(); st.pop();
                    if(at==y){
                        found=true;
                        break;
                    }
                    for(int eto: adj[at]) {
                        if(!active[eto]) continue;
                        auto [a,b] = es[eto];
                        int to = dsu.find(a)^dsu.find(b)^at;
                        if(!vis[to]) {
                            st.push(to);
                            vis[to]=true;
                        }
                    }
                }
                vis[x]=false;
                vis[y]=false;
                ans.push_back(found);
                last=found;
            }
        }
    }
    for(auto i : ans) {
        cout << i;
    } cout << '\n';
}