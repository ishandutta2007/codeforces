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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi deg(n);
        vvi adj(n);
        vector<array<int,2>> es(n-1);
        int id=0;
        for(auto& [u,v] : es){
            cin >> u >> v;
            --u,--v;
            deg[u]++,deg[v]++;
            adj[u].push_back(id);
            adj[v].push_back(id++);
        }
        if(*max_element(all(deg))>2) {
            cout << "-1\n";
        } else {
            vector<bool> vis(n);
            int at = min_element(all(deg))-deg.begin();
            int a=2;
            vi ans(n-1);
            while(true) {
                
                int ei,to=-1;
                for(auto i : adj[at]) {
                    auto& e = es[i];
                    int tmp = e[0]^e[1]^at;
                    if(!vis[tmp]) {
                        to=tmp;
                        ei=i;
                    }
                }
                if(to==-1) break;
                ans[ei]=a;
                a = 5-a;
                vis[at]=true;
                at=to;
                
            }
            cout << ans << '\n';

        }
    }
}