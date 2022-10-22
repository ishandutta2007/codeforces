#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll q[mn],w[mn];
ll hail(ll x){
    if(x&1)return x*(x-1)/2+1;
    else return x*x/2;
}
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%lld%lld",q+i,w+i);
    sort(w,w+m,greater<ll>());
    ll ans=0;
    for(i=0;i<m;i++){
        if(hail(i+1)<=n)ans+=w[i];
    }
    printf("%lld",ans);
}