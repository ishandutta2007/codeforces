#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000010,mod=1e9+7;
int i,j,k,n,m,a[maxn];
ll jc[maxn],ny[maxn];
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
ll C(int x,int y){
    if(y<0 || y>x)return 0;
    return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
string S;
int main(){
    jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
    ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
    int T=1;
    while(T--){
        cin>>n;cin>>m;
        k=m;
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            k+=C(m+i,i+1);
            k%=mod;
            // cerr<<C(m+i,i+1)<<' '<<m+1<<endl;
        }
        cout<<k<<endl;
    }
}