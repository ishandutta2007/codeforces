#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll t[3][3],X[3][3],ans[3][3];
void mult(ll a[3][3],ll b[3][3]){
    memset(t,0,sizeof(t));
    int i,j,k;
    for(i=0;i<3;i++)for(j=0;j<3;j++)for(k=0;k<3;k++)t[i][k]=(t[i][k]+a[i][j]*b[j][k])%(mod-1);
    memcpy(b,t,sizeof(t));
}
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int main(){
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    a=(a*d%mod);
    b=b*d%mod*d%mod;
    c=c*d%mod*d%mod*d%mod;
    X[0][0]=X[0][1]=X[0][2]=X[1][0]=X[2][1]=1;
    ans[0][0]=ans[1][1]=ans[2][2]=1;
    ll k=n-3;
    for(;k;k>>=1,mult(X,X))if(k&1)mult(X,ans);
    ll hail=po(c,ans[0][0])*po(b,ans[0][1])%mod*po(a,ans[0][2])%mod*po(d,(-n)%(mod-1)+(mod-1))%mod;
    printf("%lld",hail);
}