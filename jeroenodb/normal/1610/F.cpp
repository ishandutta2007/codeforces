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
int main() {
    int n,m; cin >> n >> m;
    struct edge {
        int at,to,w;
        void read() {
            cin >> at >> to >> w;
            --at,--to,--w;
        }
        int ans=-1;
        bool vis() {
            return ans!=-1;
        }
        void setAns(int source) {
            if(source==at) ans=1;
            else ans=2;
        }
        int o(int x) {return at^x^to;}
    };
    vector<edge> es(m);
    vi deg[2] = {vi(n),vi(n)};
    vvi adj[2] = {vvi(n),vvi(n)};
    
    for(int i=0;i<m;++i) {
        auto& e = es[i];
        e.read();
        adj[e.w][e.at].push_back(i);
        adj[e.w][e.to].push_back(i);
        deg[e.w][e.at]++;
        deg[e.w][e.to]++;
    }
    int ans=0;
    for(int i=0;i<n;++i) ans+=deg[0][i]%2;
    cout << ans << '\n';
    auto takeE = [&](int j, int at) {
        while(true) {
            int ei = adj[j][at].back();
            auto& e = es[ei];
            if(e.vis()) {
                adj[j][at].pop_back();
            } else {
                e.setAns(at);
                deg[j][at]--;
                deg[j][e.o(at)]--;
                return e.o(at);
            }
        }
    };
    auto makePath = [&](int at, bool whatever=false) {
        bool use=0;
        if(whatever) {
            if(deg[0][at]) at = takeE(0,at),use=0;
            else if(deg[1][at]) at = takeE(1,at),use=1;
        }
        while(true) {
            if(deg[use][at]%2==1) at = takeE(use,at);
            else if(deg[!use][at]%2==1) at = takeE(!use,at), use=!use;
            else break;
        }
    };
    for(int i=0;i<n;++i) while( (deg[0][i]+deg[1][i])%2==1)makePath(i);
    for(int i=0;i<n;++i) while(deg[0][i]+deg[1][i]>0) 
        makePath(i,true);
    for(auto& e : es) cout << e.ans;
    cout << '\n';
}