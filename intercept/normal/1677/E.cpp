#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,q;
struct Bit{
    ll bit[M];
    void add(int x,ll v){
        for(;x<=n;x+=x&-x)bit[x]+=v;
    }
    ll ask(int x,ll rex=0){
        for(;x;x-=x&-x)rex+=bit[x];
        return rex;
    }
}a,b,c,d;
void add(ll l,ll v,ll j){
    a.add(l,v);
    b.add(l,-(l-1)*v);
    c.add(l,-(j-1)*v);
    d.add(l,(l-1)*(j-1)*v);
}
void add(ll l,ll r,ll v,ll j){
    if(l>r)return;
    add(l,v,j);
    add(r+1,-v,j);
}
ll ask(int x,int y){
    return a.ask(x)*x*y+b.ask(x)*y+c.ask(x)*x+d.ask(x);
}
int p[M],id[M];
vector<pii>g[M];
int top,s[M],L[M],in[M];
ll ans[M*5];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&p[i]),id[p[i]]=i;
    for(int i=1;i<=q;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        g[r].eb(l,i);
    }
    for(int i=1;i<=n;++i){
        while(top&&p[s[top]]<p[i]){
            add(s[top-1]+1,L[s[top]],-1,i);
            
            in[s[top]]=0;
            top--;
        }
        s[++top]=i;
        L[i]=max(s[top-1],L[i]);
        in[i]=1;
        
        add(s[top-1]+1,L[i],1,i);
        for(int j=p[i];j<=n;j+=p[i]){
            if(i<=id[j/p[i]])continue;
            int x=min({id[p[i]],id[j/p[i]],id[j]});
            if(L[id[j]]<x){
                if(in[id[j]]){
                    add(L[id[j]]+1,x,1,i);
                }
                L[id[j]]=x;
            }
        }
        for(auto o:g[i]){
            ans[o.se]=ask(i,i)-ask(o.fi-1,i);
        }
    }
    for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
    return 0;
}