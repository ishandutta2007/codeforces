#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=10;
ll a[mn],p[mn];
ll fact[mn];
ll num[mn],np[mn];
int n;
ll hail(){
    for(int i=0;i<n;i++)num[i]=1;
    ll ans=0;
    int rt=0;
    for(int i=0;i<n;i++)if(np[i]!=1)ans++;
    for(int i=0;i<n;i++){
        if(a[i]%num[i]!=0)return 0x3f3f3f3f;
        if(p[i]==i)ans+=np[i],rt++;
        else if(a[i]<=a[p[i]]/num[p[i]])num[p[i]]*=a[i];
        else num[p[i]]=a[p[i]]+1;
    }
    if(rt>1)ans++;
    return ans;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    sort(a,a+n);
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i;
    ll ans=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        ll x=a[i];
        for(ll j=2;j*j<=x;j++){
            while(x%j==0){
                x/=j,np[i]++;
            }
        }
        if(x!=1)np[i]++;
    }
    for(int i=0;i<fact[n];i++){
        for(int j=0;j<n;j++){
            p[n-1-j]=n-1-i/fact[j]%(j+1);
        }
        ans=min(ans,hail());
    }
    printf("%lld",ans);
}