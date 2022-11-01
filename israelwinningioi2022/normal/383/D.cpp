#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;

const int N = 1010, M = 1e4 + 10;
int dp[2][2*M]; int cur = 0, nxt = 1;
void add(int &a, int b){
    a = (a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    loop(i,0,2*M) dp[cur][i] = 0;
    int ans = 0;
    loop(i,0,n){
        loop(j,0,2*M) dp[nxt][j] = 0;
        add(dp[cur][M],1);
        loop(j,0,2*M){
            if (j+a[i]<2*M) add(dp[nxt][j+a[i]], dp[cur][j]);
            if (j-a[i]>=0) add(dp[nxt][j-a[i]], dp[cur][j]);
        }
        swap(nxt, cur);
        add(ans, dp[cur][M]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ antimatter.cpp -o a & a
4
1 1 1 1
 
*/