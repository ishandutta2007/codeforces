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
const int INF = 2e18;

const int N = 81;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    int cnt = 0, sz=0;
    vi group;
    loop(i,0,n){
        if (a[i]) group.pb(cnt), cnt=0;
        else cnt++, sz++;
    }
    group.pb(cnt);
    int ans = sz*sz;
    int m = group.size();
    vi pref(m); pref[0] = group[0];
    loop(i,1,m) pref[i] = pref[i-1] + group[i];
    int dp[2][N+1][(N*N)/2+1]; int cur = 0, nxt = 1;
    int amt = n*(n-1)/2;
    loop(j,0,sz+1) loop(k,0,amt+1) dp[cur][j][k] = INF;
    dp[cur][0][0] = 0;
    loop(i,0,m){
        loop(j,0,sz+1) loop(k,0,amt+1) dp[nxt][j][k] = INF;
        loop(x,0,sz+1){
            loop(y,0,amt+1){
                if (dp[cur][x][y]==INF) continue;
                loop(dx,0,sz+1-x){
                    int op = y + abs(pref[i]-(x+dx));
                    if (op<=amt) chkmin(dp[nxt][x+dx][op], dp[cur][x][y] + dx*dx);
                }
            }
        }
        //loop(x,0,sz+1) loop(y,0,amt) chkmin(dp[nxt][x][y+1], dp[nxt][x][y]);
        swap(cur, nxt);
    }
    loop(i,0,amt) chkmin(dp[cur][sz][i+1], dp[cur][sz][i]);
    loop(i,0,amt+1) cout<<(ans-dp[cur][sz][i])/2<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
5
1 0 0 0 1

*/