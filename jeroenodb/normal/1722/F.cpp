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
typedef complex<short> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<string> g(n);
        for(auto& i : g) cin >> i;
        bool good=true;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(g[i][j]=='*') {
            int lo=oo,hi=-oo,sz=0;
            int lo2=oo,hi2=-oo;
            auto dfs = [&](auto&& self,pt at) -> void{
                lo = min(lo,(int)at.X);
                hi = max(hi,(int)at.X);
                lo2 = min(lo2,int(at.Y));
                hi2 = max(hi2,int(at.Y));
                sz++;
                g[at.X][at.Y]='.';
                for(auto to : dir8) {
                    to+=at;
                    if(inside(to) and g[to.X][to.Y]=='*') {
                        self(self,to);
                    }
                }
            };
            dfs(dfs,pt{i,j});
            good &= sz==3 and hi-lo==1 and hi2-lo2==1;
            
        }
        cout << (good?"YES\n":"NO\n");
    }
}