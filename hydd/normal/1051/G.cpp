#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,fa[410000],rt[410000],R[410000]; ll ans;
int treesize,ls[11000000],rs[11000000],t[11000000];
ll s[11000000];

int findset(int x){
    if (x!=fa[x]) fa[x]=findset(fa[x]);
    return fa[x];
}
ll calc(int x){
    return 1ll*t[rs[x]]*s[ls[x]];
}

void pushup(int x){
    s[x]=s[ls[x]]+s[rs[x]];
    t[x]=t[ls[x]]+t[rs[x]];
}
void change(int &now,int l,int r,int x){
    if (!now) now=++treesize;
    if (l==r){
        s[now]+=x;
        t[now]++;
        return;
    }
    int mid=(l+r)>>1; ans-=calc(now);
    if (x<=mid) change(ls[now],l,mid,x);
    else change(rs[now],mid+1,r,x);
    ans+=calc(now); pushup(now);
}
int Merge(int a,int b){
    if (!a||!b) return a|b;
    ans-=calc(a); ans-=calc(b);
    ls[a]=Merge(ls[a],ls[b]);
    rs[a]=Merge(rs[a],rs[b]);
    ans+=calc(a); pushup(a);
    return a;
}

void Union(int u,int v){
    u=findset(u); v=findset(v);
    ans-=1ll*s[rt[v]]*(v-u);
    fa[v]=u; R[u]=R[v]; rt[u]=Merge(rt[u],rt[v]);
}

int main(){
    cin>>n; int x,y;
    for (int i=1;i<=400000;i++) fa[i]=i;
    for (int i=1;i<=n;i++){
        cin>>x>>y; int u=findset(x);
        change(rt[u],1,n,y); ans-=1ll*(x-u)*y;
        
        int pos=(R[u]?R[u]+1:x); R[u]=pos; fa[pos]=u;
        if (R[findset(u-1)]) Union(u-1,u);
        if (R[pos+1]) Union(pos,pos+1);
        cout<<ans<<'\n';
    }
    return 0;
}