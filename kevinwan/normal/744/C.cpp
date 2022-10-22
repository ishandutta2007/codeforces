#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
int c[mn],a[mn],b[mn];
char s[2];
int dp[1<<16][129];
int main(){
    int n;
    scanf("%d",&n);
    int num1=0;
    for(int i=0;i<n;i++)scanf("%s%d%d",s,a+i,b+i),c[i]=(s[0]=='B'),num1+=c[i];
    if(num1<=n/2){
        for(int i=0;i<n;i++)c[i]^=1,swap(a[i],b[i]);
    }
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<1<<n;i++){
        int v[2]={0,0};
        for(int j=0;j<n;j++)if((i>>j)&1)v[c[j]]++;
        for(int j=0;j<n;j++)if((i>>j)&1^1){
            for(int k=min(a[j],v[0]);k<=128;k++){
                dp[i+(1<<j)][k]=max(dp[i+(1<<j)][k],dp[i][k-min(a[j],v[0])]+min(b[j],v[1]));
            }
        }
    }
    int sa=n,sb=n;
    for(int i=0;i<n;i++)sa+=a[i],sb+=b[i];
    int ans=0x3f3f3f3f;
    for(int i=0;i<=128;i++)ans=min(ans,max(sa-i,sb-dp[(1<<n)-1][i]));
    printf("%d",ans);
}