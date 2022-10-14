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
const int mxN = 1e5+1, oo = 1e9;
void solve() {
    int n; cin >> n;
    struct IV {
        int l,r;
        bool c;
    };
    vector<vector<IV>> ccs(n,{{}});
    for(auto& cc : ccs) for(auto& iv : cc) cin >> iv.c >> iv.l >> iv.r;
    bool done=false;
    while(!done) {
        n = ccs.size();
        done=true;
        map<int,int> s[2];
        s[0][0]=-1;
        s[1][0]=-1;
        auto get = [&](map<int,int>& ss, int x) {
            auto it = ss.upper_bound(x);
            return prev(it)->second;
        };
        auto cut = [&](map<int,int>& ss, int x) {
            ss[x]=get(ss,x);
        };
        auto add = [&](map<int,int>& ss, int l, int r, int v) {
            cut(ss,r+1);
            auto it = ss.upper_bound(l);
            while(it!=ss.end() and it->first<=r) it = ss.erase(it);
            ss[l]=v;
        };
        
        vvi adj(n);
        auto addE = [&](int i, int j) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        };
    
        for(int i=0;i<n;++i) {
            auto& cc = ccs[i];
            bool found=false;
            for(auto& iv : cc) {
                auto& ss = s[!iv.c];
                auto it = prev(ss.upper_bound(iv.l));
                while(it!=ss.end() and it->first<=iv.r) {
                    if(it->second!=-1) {
                        found=true;
                        done=false;
                        addE(it->second,i);
                        break;
                    }
                    ++it;
                }
                if(found) break;
            }
            for(auto& iv : cc) {
                auto& ss = s[iv.c];
                add(ss,iv.l,iv.r,i);
            }
        }
        vi cmp(n,-1);
        int nw=0;
        for(int i=0;i<n;++i) if(cmp[i]==-1) {
            vi q;
            auto process = [&](int at) {
                if(cmp[at]==-1) {
                    cmp[at]=nw;
                    q.push_back(at);
                }
            };
            process(i);
            for(int i=0;i<(int)q.size();++i) {
                int at = q[i];
                for(auto to : adj[at]) process(to);
            }
            nw++;
        }
        vector<vector<IV>> ncs(nw);
        for(int i=0;i<n;++i) {
            for(auto& iv : ccs[i]) ncs[cmp[i]].push_back(iv);
        }
        ccs=ncs;
    }
    cout << ccs.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}