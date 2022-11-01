#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 4e18;


int solve(){
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    sort(all(a));
    vvi dp(n+1, vi(2*n+1, INF));
    dp[0][0] = 0;
    loop(i,0,n){
        loop(j,0,2*n){
            int d = abs(a[i]-(j+1));
            chkmin(dp[i][j+1], dp[i][j]);
            chkmin(dp[i+1][j+1], dp[i][j]+d);
        }
    }
    int ans = INF;
    loop(i,0,2*n+1) chkmin(ans, dp[n][i]);
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6
6
4 2 4 4 5 2
7
7 7 7 7 7 7 7
1
1
5
5 1 2 4 3
4
1 4 4 4
21
21 8 1 4 1 5 21 1 8 21 11 21 11 3 12 8 19 15 9 11 13


*/