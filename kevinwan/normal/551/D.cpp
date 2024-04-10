#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l,m;
ll t[2][2],ans[2][2]={{1,0},{0,1}},T[2][2]={{1,1},{1,0}};
void mult(ll a[2][2],ll b[2][2]){
    memset(t,0,sizeof(t));
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)t[i][k]=(t[i][k]+a[i][j]*b[j][k])%m;
    memcpy(b,t,sizeof(t));
}
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%m)if(b&1)ans=ans*a%m;
    return ans;
}
void pom(ll b){
    for(;b;b>>=1,mult(T,T))if(b&1)mult(T,ans);
}
int main(){
    cin>>n>>k>>l>>m;
    pom(n+2);
    ll zero=ans[0][1];
    ll one=po(2,n)-zero;
    ll ans=1%m;
    for(int i=0;i<l;i++){
        if(k&1)ans=ans*one%m;
        else ans=ans*zero%m;
        k>>=1;
    }
    if(k)ans=0;
    if(ans<0)ans+=m;
    printf("%lld",ans);
}