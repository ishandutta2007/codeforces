#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=3e5+9;
int n,q;
ll x[M],w[M];
vector<pii>g[M];
int top,s[M];
ll bit[M],ans[M];
void add(int x,ll v){
    for(;x;x-=x&-x)bit[x]=min(bit[x],v);
}
ll ask(int x,ll rex=1ll<<62){
    for(;x<=n;x+=x&-x)rex=min(bit[x],rex);
    return rex;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%lld%lld",&x[i],&w[i]);
        bit[i]=1ll<<62;
    }
    for(int i=1;i<=q;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        g[r].eb(l,i);
    }
    for(int i=1;i<=n;++i){
        while(top&&w[i]<=w[s[top]]){
            ll rex=(w[i]+w[s[top]])*(x[i]-x[s[top]]);
            add(s[top],rex);
            top--;
        }
        if(top){
            ll rex=(w[i]+w[s[top]])*(x[i]-x[s[top]]);
            add(s[top],rex);
        }
        s[++top]=i;
        for(auto o:g[i]){
            ans[o.se]=ask(o.fi);
        }
    }
    for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
    return 0;
}
/*
5 : 3
*/