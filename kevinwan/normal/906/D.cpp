#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
struct nd{
    int m;
    vector<nd*>xt;
    vector<int>p,num,v;
};
void init(nd*n){
    int v=n->m;
    for(int i=2;i*i<=v;i++){
        int num=1,ct=0;
        while(v%i==0){
            v/=i,num*=i,ct++;
        }
        if(num>1){
            n->v.push_back(num);
            n->p.push_back(i);
            n->num.push_back(ct);
            n->xt.push_back(new nd());
            n->xt.back()->m=num/i*(i-1);
        }
    }
    if(v>1){
        n->v.push_back(v);
        n->p.push_back(v);
        n->num.push_back(1);
        n->xt.push_back(new nd());
        n->xt.back()->m=v-1;
    }
    for(auto x:n->xt)init(x);
}
ll po(ll a,ll b,ll m){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=m)if(b&1)ans*=a,ans%=m;
    return ans;
}
ll spo(ll a,ll b,ll m=2e9){
    ll ans=1;
    for(;b;b>>=1,a*=a,a=min(a,m))if(b&1)ans*=a,ans=min(ans,m);
    return ans;
}
nd*r=new nd();
int a[mn];
vector<ll>pre[mn];
ll solve(int l,int r,nd*n){
    if(n->m==1)return 0;
    if(l==r)return a[l]%n->m;
    if(a[l]==1)return 1;
    vector<ll>ans(n->v.size());
    for(int i=0;i<n->v.size();i++){
        ll re;
        if(r-l<pre[l+1].size())re=pre[l+1][r-l-1];
        else re=pre[l+1].back();
        if(po(a[l],re,n->v[i])==0)ans[i]=0;
        else ans[i]=po(a[l],solve(l+1,r,n->xt[i]),n->v[i]);
    }
    ll eu=1,ret=0,pro=1;
    for(int i=0;i<ans.size();i++){
        ll mod=pro*n->v[i];
        ret=(ret*n->v[i]%mod*po(n->v[i],eu-1,pro)%mod+ans[i]*pro%mod*po(pro,n->xt[i]->m-1,n->v[i])%mod)%mod;
        eu*=n->xt[i]->m;
        pro=mod;
    }
    return ret;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    r->m=m;
    init(r);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=n;i>=1;i--){
        pre[i].push_back(a[i]);
        for(int j=i+1;j<=n&&pre[i].back()!=2e9&&pre[i].back()!=1&&a[j-1]!=1;j++)pre[i].push_back(spo(a[i],pre[i+1][j-i-1]));
    }
    pre[n+1].push_back(0);
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",solve(a,b,r));
    }
}