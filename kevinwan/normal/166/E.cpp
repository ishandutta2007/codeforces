#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007LL
ll t[4][4],ans[4][4],tr[4][4];
void mult(ll a[4][4],ll b[4][4],ll c[4][4]){
    memset(t,0,sizeof(t));
    int i,j,k;
    for(i=0;i<4;i++)for(j=0;j<4;j++)for(k=0;k<4;k++)t[i][k]+=b[i][j]*c[j][k],t[i][k]%=mod;
    for(i=0;i<4;i++)for(j=0;j<4;j++)a[i][j]=t[i][j];
}
int main(){
    ll n;
    int i,j;
    scanf("%lld",&n);
    for(i=0;i<4;i++)ans[i][i]=1;
    for(i=0;i<4;i++)for(j=0;j<4;j++)tr[i][j]=1-ans[i][j];
    for(;n;n>>=1,mult(tr,tr,tr)){
        if(n&1)mult(ans,ans,tr);
    }
    if(ans[0][0]<0)ans[0][0]+=mod;
    printf("%lld",ans[0][0]);
}