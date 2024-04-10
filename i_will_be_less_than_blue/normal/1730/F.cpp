
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=5010;
const int inf=2e9;
int dp[N][9][(1<<8)];
int add[N][N];
int p[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        p[x]=i;
    }
    if (n<=k+1){
        cout<<0<<endl;
        return;
    }

    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            for (int mask=0;mask<(1<<k);mask++){
                dp[i][j][mask]=inf;
            }
        }
    }
    for (int i=1;i<=min(n,k+1);i++){
        dp[1][i-1][0]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            add[i][j]=add[i-1][j]+(p[i]>p[j]);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<=k;j++){
            for (int mask=0;mask<(1<<k);mask++){
                if (dp[i][j][mask]==inf) continue;
                for (int t=max(1,i+j-k);t<i+j;t++){
                    int ind=t-(i+j-k);
                    if (mask&(1<<ind)) continue;
                    int delta=add[max(1,i+j-k)-1][t];
                    for (int el=0;el<k;el++){
                        if (mask&(1<<el)){
                            if (p[el+(i+j-k)]>p[t]) delta++;
                        }
                    }
                    if (p[i+j]>p[t]) delta++;

                    dp[i+1][j-1][mask^(1<<ind)]=min(dp[i+1][j-1][mask^(1<<ind)],dp[i][j][mask]+delta);
                }
                int mn=i+1;
                for (int t=0;t<k;t++){
                    if (!(mask&(1<<t))){
                        if ((i+j-k)+t>=1) mn=min(mn,(i+j-k)+t);
                    }
                }
                for (int t=i+j+1;t<=min(n,mn+k);t++){
                    int delta=add[max(1,i+j-k)-1][t];
                    for (int el=0;el<k;el++){
                        if (mask&(1<<el)){
                            if (p[el+(i+j-k)]>p[t]) delta++;
                        }
                    }
                    if (p[i+j]>p[t]) delta++;

                    int nxt_mask=((mask^(1<<k))>>(t-(i+j)));
                    dp[i+1][t-i-1][nxt_mask]=min(dp[i+1][t-i-1][nxt_mask],dp[i][j][mask]+delta);
                }
            }
        }
    }
    cout<<dp[n][0][(1<<k)-1]<<'\n';








}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**
5 2
3 1 4 5 2




2 5 1 3 4

0 0 2 1 1
**/