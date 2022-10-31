#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e3+7;
int A[N][N],sum[N][N];
int n,m,q;
void calc_diag(){
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            sum[i][j] = sum[i-1][j-1]+A[i][j];
}
int calc(int i,int j){
    if (i==0 || j==0)
        return 0;
    int ret = 0;
    while(i<=n && j<=m){
        int l = 0,r = min(n-i+1,m-j+1);
        while(l!=r){
            int tm = (l+r+1)>>1;
            if (sum[i+tm-1][j+tm-1]-sum[i-1][j-1]!=tm || sum[i+tm-1][j+tm]-sum[i-1][j]!=tm)
                r = tm-1;
            else l = tm;
        }
        int cnt = l*2;
        if (A[i+l][j+l])
            ++cnt;
        if (A[i-1][j])
            cnt*=2;
        ret+=cnt;
        ++i,++j;
    }
    return ret;
}
void re_sum(int i,int j){
    while(i<=n && j<=m){
        sum[i][j] = sum[i-1][j-1]+A[i][j];
        ++i,++j;
    }
}
void solve(){

    cin>>n>>m>>q;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            A[i][j] = 1;
    calc_diag();
    ll res = 0;
    for(int i = 1;i<=n;++i)
        res+=calc(i,1);
    for(int j = 1;j<=m;++j)
        res+=calc(1,j);
    res-=calc(1,1);

    while(q--){
        int x,y;
        cin>>x>>y;
        int g = min(x-1,y-1);
        int x1 = x-g,y1 = y-g;
        res-=calc(x1,y1);
        g = min(x-1,y-2);
        int x2 = x-g,y2 = y-1-g;
        res-=calc(x2,y2);
        A[x][y]^=1;
        re_sum(x1,y1);
        res+=calc(x1,y1);
        res+=calc(x2,y2);
        cout<<res<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)
        solve();
}