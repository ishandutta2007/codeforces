//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef pair<int, int> Pii;
typedef long long ll;
//#define prev aboba
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
vector<pair<int,int> >ans;
const int N=5010;
const ll inf=1e18;
int s[N];
ll dp[N][N][2];
void solve(){
    ll n,x,y;cin>>n>>x>>y;
    string a;cin>>a;
    string b;cin>>b;
    for (int i=0;i<n;i++) s[i]=(a[i]!=b[i]);
    int cnt=0;
    int l=n+1;
    int r=-1;
    for (int i=0;i<n;i++){
        cnt+=s[i];
        if (s[i]){
            l=min(l,i);
            r=max(r,i);
        }
    }
    if (cnt%2){
        cout<<-1<<endl;
        return;
    }
    if (x>=y){
        if (cnt==2 && l+1==r){
            cout<<min(x,2*y)<<'\n';
        } else {
            cout<<(cnt/2)*1ll*y<<'\n';
        }
        return;
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int t=0;t<2;t++){
                dp[i][j][t]=inf;
            }
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++){
            if ((i+j)%2==s[0]) dp[0][i][j]=i*y+j*x;
        }
    }

    for (int i=0;i<n-1;i++){
        for (int j=0;j<=n;j++){
            for (int t=0;t<2;t++){
                dp[i][j+2][t]=min(dp[i][j+2][t],dp[i][j][t]+y*2);
//                cout<<i<<" "<<j<<" "<<t<<" "<<dp[i][j][t]<<endl;
                for (int j1=0;j1<2;j1++){
                    for (int t1=0;t1<2;t1++){
                        int nxtj=j+j1-(s[i+1]^t^t1^j1);
                        if (nxtj<0) continue;
                        dp[i+1][nxtj][t1]=min(dp[i+1][nxtj][t1],dp[i][j][t]+t1*x+j1*y);
                    }
                }


            }
        }
    }
    ll res=inf;
    for (int i=0;i<=n;i++){
        res=min(res,dp[n-1][i][0]);
    }
    cout<<res<<'\n';






}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
18
89 32 12 4 13 3 89 32 12 4 13 3 89 32 12 4 13 3
*/