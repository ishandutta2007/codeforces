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
const int mxN = 80+1, oo = 1e9, M = 3200;
int dp[2][M][mxN];
void cmax(int& a, int b) {a=max(a,b);}
int main() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    // sauce used (last dimension) 
    vi b = {0};
    for(int i=0;i<n;++i) {
        if(a[i]==1) b.push_back(b.back());
        else b.back()++;
    }
    if(b.size()==1) {
        for(int i=0;i<=n*(n-1)/2;++i) 
            cout << "0 ";
        exit(0);
    }
    // dp[shields used][moves][sauce used]
    int mxs = b.back(), S = b.size()-1;
    auto clear = [&](int k) {
        for(int i=0;i<M;++i) {
            fill_n(dp[k][i],mxs+1,-oo);
        }
    };
    clear(1);
    dp[1][0][0]=0;
    
    for(int i=0;i<S;++i) {
        auto sh = b[i];
        clear(i%2);
        auto nw = dp[i%2], old = dp[(i+1)%2];
        for(int mov=0;mov<M;++mov) {
            for(int sc=0;sc<=mxs;++sc) {
                auto cur = old[mov][sc];
                if(cur==-oo) continue;
                for(int scn = sc;scn<=mxs;++scn) {
                    auto score = cur+sc*(scn-sc);
                    int nwmov = abs(sh-scn) + mov;
                    if(nwmov<M) {
                        cmax(nw[nwmov][scn],score);
                    }
                }
            }
        }
    }
    auto res = dp[(S-1)%2];
    int ans=0;
    for(int mv=0;mv<= n*(n-1)/2;++mv) {

        for(int sc=0;sc<=mxs;++sc) {
            cmax(ans, res[mv][sc]+ sc*(mxs-sc));
        }
        cout << ans << ' ';
    }
}