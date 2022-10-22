#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define foz(i,a,b) for(int i=(a);i<(b);++i)
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
struct op{
    ll a,b;
    op operator*(const op&ot)const{return {a*ot.a%mod,(b*ot.a+ot.b)%mod};}
};
const int mn=2e5+10;
ll p[mn];
op sp[mn][18];
ll qu(ll a,ll b){
    op ans={0,0};
    ++b;
    for(int i=17;i>=0;i--){
        if(a+(1<<i)<=b)ans=ans*sp[a][i],a+=1<<i;
    }
    return ans.b;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    foz(i,1,n+1)scanf("%lld",p+i),p[i]=100*po(p[i])%mod;
    foz(i,1,n+1)sp[i][0]={p[i],p[i]};
    foz(i,1,18)for(int j=1;j+(1<<i)<=n+1;j++)sp[j][i]=sp[j][i-1]*sp[j+(1<<i-1)][i-1];
    set<int>s;
    s.insert(1);
    s.insert(n+1);
    ll ans=qu(1,n);
    while(q--){
        int x;
        scanf("%d",&x);
        auto it=s.lower_bound(x);
        if(*it==x){
            int a=*(--it);
            int b=*(++(++it));
            ans-=qu(a,x-1);
            ans-=qu(x,b-1);
            ans+=qu(a,b-1);
            ans%=mod;
            s.erase(x);
        }
        else{
            int b=*it;
            int a=*(--it);
            ans+=qu(a,x-1);
            ans+=qu(x,b-1);
            ans-=qu(a,b-1);
            ans%=mod;
            s.insert(x);
        }
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
}