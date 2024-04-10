//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5010;
const ll mod=1e9+7;
ld dp[5010][5010],p[5010];
ld pre[2][5010];
int t[5010];
ld vesh[mn];
int main(){
    int N,T;
    cin>>N>>T;
    for(int i=1;i<=N;i++)cin>>p[i]>>t[i],p[i]/=100,vesh[i]=pow(1-p[i],t[i]-1);
    dp[0][0]=1;
    if(t[1]!=1)pre[0][0]=1;
    ld ans=0;
    for(int i=1;i<=T;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]=pre[i&1^1][j-1]*p[j];
            if(i>=t[j]){
                if(1-p[j]!=0)dp[i][j]+=dp[i-t[j]][j-1]*vesh[j];
                else if(t[j]==1)dp[i][j]+=dp[i-t[j]][j-1];
            }
            ans+=dp[i][j];
        }
        for(int j=0;j<N;j++){
            pre[i&1][j]=pre[i&1^1][j]*(1-p[j+1])+dp[i][j];
            if(i-t[j+1]+1>=0)pre[i&1][j]-=dp[i-t[j+1]+1][j]*vesh[j+1];
        }
    }
    printf("%.20lf",ans);
}