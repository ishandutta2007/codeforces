//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10;
const ll mod=1e9+7;
int bit[mn];
void upd(int a,int b){for(a++;a<mn;a+=a&-a)bit[a]=max(bit[a],b);}
int qu(int a){int b=0;for(a++;a;a-=a&-a)b=max(bit[a],b);return b;}
int v[mn];
void die(){
    printf("NO");
    exit(0);
}
int dp[mn][2],ans[mn];
int main(){
    //freopen("hail.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",v+i);
    dp[1][0]=0x3f3f3f3f;
    dp[1][1]=0xc0c0c0c0;
    for(int i=2;i<=n;i++)dp[i][1]=0x3f3f3f3f,dp[i][0]=0xc0c0c0c0;
    for(int i=2;i<=n;i++){
        if(v[i]>v[i-1])dp[i][0]=max(dp[i][0],dp[i-1][0]);
        if(v[i]>dp[i-1][1])dp[i][0]=max(dp[i][0],v[i-1]);
        if(v[i]<v[i-1])dp[i][1]=min(dp[i][1],dp[i-1][1]);
        if(v[i]<dp[i-1][0])dp[i][1]=min(dp[i][1],v[i-1]);
    }
    if(dp[n][0]==0xc0c0c0c0&&dp[n][1]==0x3f3f3f3f)die();
    for(int i=n,j=(dp[n][0]==0xc0c0c0c0);i;i--){
        ans[i]=j;
        if(!j){
            if(v[i]>v[i-1]&&dp[i][0]==dp[i-1][0]);
            else j=1;
        }
        else{
            if(v[i]<v[i-1]&&dp[i][1]==dp[i-1][1]);
            else j=0;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}