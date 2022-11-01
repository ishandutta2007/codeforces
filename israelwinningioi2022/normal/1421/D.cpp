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

int calc(int x, int y, int px, int nx, int py, int ny){
    int ans = 0;
    ans += (x>0?px:nx) * abs(x);
    ans += (y>0?py:ny) * abs(y);
    return ans;
}
int n = 6;
int solve(){
    int x,y; cin>>x>>y; swap(x,y);
    vi c(n+1); loop(i,1,n+1) cin>>c[i];
    int ans = calc(x,y,c[2],c[5],c[6],c[3]);
    chkmin(ans, calc(x-y, y, c[2], c[5], c[1], c[4]));
    chkmin(ans, calc(x, y-x, c[1], c[4], c[6], c[3]));
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
g++ d.cpp -o a & a
2
-3 1
1 3 5 7 9 11
1000000000 1000000000
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000

*/