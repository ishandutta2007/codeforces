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
    vector<string> mat(n);
    loop(i,0,n) cin>>mat[i];
    vii vec = {{mat[0][1],0}, {mat[1][0],1}, {mat[n-1][n-2],2}, {mat[n-2][n-1],3}};
    //vi vv = vec;
    vii pos = {{0,1},{1,0},{n-1,n-2},{n-2,n-1}};
    vii ans;
    if (vec[0].x==vec[1].x){
        loop(i,2,4){
            if (vec[i].x==vec[0].x){
                ans.pb(pos[i]);
            }
        }
    }
    else if (vec[2].x==vec[3].x){
        loop(i,0,2){
            if (vec[i].x==vec[2].x){
                ans.pb(pos[i]);
            }
        }
    }
    else{
        ans.pb(pos[1]);
        loop(i,2,4){
            if (vec[i].x==vec[0].x){
                ans.pb(pos[i]);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.x+1<<" "<<p.y+1<<endl;
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
3
4
S010
0001
1000
111F
3
S10
101
01F
5
S0101
00000
01111
11111
0001F

*/