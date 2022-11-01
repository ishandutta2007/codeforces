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
    int n,m; cin>>n>>m;
    vvi mat(n, vi(m));
    loop(i,0,n) loop(j,0,m) cin>>mat[i][j];
    int ans = 0;
    loop(i,0,n) loop(j,0,m){
        if (mat[i][j]==-1) continue;
        vi vals = {mat[i][j]};
        if (i!=n-i-1) vals.pb({mat[n-i-1][j]}), mat[n-i-1][j] = -1;
        if (j!=m-j-1) vals.pb({mat[i][m-j-1]}), mat[i][m-j-1] = -1;
        if (vals.size()==3) vals.pb({mat[n-i-1][m-j-1]}), mat[n-i-1][m-j-1] = -1;
        int r = vals.size();
        int best = INF;
        loop(k,0,r) {
            int v = 0;
            loop(l,0,r) v+=abs(vals[k]-vals[l]);
            chkmin(best, v);
        }
        ans+=best;
    }
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
g++ b.cpp -o a & a
2
4 2
4 2
2 4
4 2
2 4
3 4
1 2 3 4
5 6 7 8
9 10 11 18

*/