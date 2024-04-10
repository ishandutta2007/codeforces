#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(9)<<fixed;
    int n; cin>>n;
    vi a(n), b(n);
    loop(i,0,n) cin>>a[i]>>b[i];
    int m = n*200 + 10;
    vvi dp(n+1, vi(2*m, -INF)), next(n+1, vi(2*m, -INF));
    dp[0][m] = 0;
    loop(i,0,n){
        loop(k,0,n+1){
            loop(x,0,2*m){
                if (dp[k][x]<-INF/2) continue;
                int v = min(x + b[i], 2*m-1);
                chkmax(next[k][v], dp[k][x]);
                v = a[i] - b[i];
                if (2*v <= x) chkmax(next[k+1][x - 2*v], dp[k][x] + a[i]);
            }
        }
        dp = next;
        loop(k,0,n+1) fill(all(next[k]),-INF);
    }
    loop(k,1,n+1){
        double ans = 0;
        loop(i,0,m){
            ans = max(ans, (double)dp[k][i+m]);
            double v = dp[k][i];
            v -= (m-i)/2.0;
            ans = max(ans, v);
        }
        cout<<ans<<" ";
    }
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3
6 5
6 5
10 2


*/