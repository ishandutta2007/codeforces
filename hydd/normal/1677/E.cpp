#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,q,a[210000],b[210000],rt[210000];
int top,s[210000],L[210000],R[210000]; vector<int> fac[210000];
vector<pii> tmp;
struct node{
    ll x,y;
    node(){}
    node(ll _x,ll _y):x(_x),y(_y){}
    ll calc(ll i){ return x*i+y;}
    node operator+(const node &a) const{ return node(x+a.x,y+a.y);}
    node& operator+=(const node &a){ *this=*this+a; return *this;}
    node operator*(int c){ return node(x*c,y*c);}
};
struct Node{
    int l,r; node v;
    Node(){}
    Node(int _l,int _r,node _v):l(_l),r(_r),v(_v){}
}; vector<Node> vec[210000];
struct Segment_Tree{
    int sumsize,ls[18100000],rs[18100000];
    node sum[18100000],tag[18100000];
    void change(int &now,int l,int r,int x,int y,node v){
        int u=++sumsize;
        ls[u]=ls[now]; rs[u]=rs[now];
        sum[u]=sum[now]; tag[u]=tag[now];
        now=u;

        sum[now]+=v*(min(r,y)-max(l,x)+1);
        if (x<=l&&r<=y){ tag[now]+=v; return;}
        int mid=(l+r)>>1; // pushdown(now,l,r,mid);
        if (x<=mid) change(ls[now],l,mid,x,y,v);
        if (y>mid) change(rs[now],mid+1,r,x,y,v);
    }
    node query(int now,int l,int r,int x,int y){
        if (!now) return node(0,0);
        if (x<=l&&r<=y) return sum[now];
        int mid=(l+r)>>1; //pushdown(now,l,r,mid);
        node res=tag[now]*(min(r,y)-max(l,x)+1);
        if (x<=mid) res+=query(ls[now],l,mid,x,y);
        if (y>mid) res+=query(rs[now],mid+1,r,x,y);
        return res;
    }
} T;
void add(int r1,int c1,int r2,int c2){
    // cerr<<r1<<' '<<c1<<' '<<r2<<' '<<c2<<'\n';
    vec[r1].push_back(Node(c1,c2,node(1,-(r1-1))));
    vec[r2+1].push_back(Node(c1,c2,node(-1,r2-r1+1+(r1-1))));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    top=0; s[top]=0;
    for (int i=1;i<=n;i++){
        while (top&&a[s[top]]<a[i]) top--;
        L[i]=s[top]+1; s[++top]=i;
    }
    top=0; s[top]=n+1;
    for (int i=n;i>=1;i--){
        while (top&&a[s[top]]<a[i]) top--;
        R[i]=s[top]-1; s[++top]=i;
    }
    // for (int i=1;i<=n;i++) cerr<<"i="<<i<<" L="<<L[b[i]]<<" R="<<R[b[i]]<<'\n';
    for (int i=1;i<=n;i++)
        for (int j=i+1;1ll*i*j<=n;j++)
            fac[i*j].push_back(i);
    for (int i=1;i<=n;i++){
        // cerr<<"i="<<i<<'\n';
        tmp.clear();
        for (int v:fac[i]){
            int x=v,y=i/v;
            if (b[x]>b[y]) swap(x,y);
            // L[b[i]]..min(b[i],b[x]), max(b[i],b[y])..R[b[i]]
            tmp.push_back(pii(b[y],b[x]));
        }
        sort(tmp.begin(),tmp.end());
        int pos=L[b[i]];
        for (pii u:tmp){
            int y=u.first,x=u.second; if (y>R[b[i]]) break;
            if (pos<=min(b[i],x)){ add(pos,max(b[i],y),min(b[i],x),R[b[i]]); pos=min(b[i],x)+1;}
        }
    }
    for (int i=1;i<=n;i++){
        rt[i]=rt[i-1];
        for (Node v:vec[i])
            T.change(rt[i],1,n,v.l,v.r,v.v);
        // cerr<<T.sum[rt[i]].x<<'#'<<T.sum[rt[i]].y<<'\n';
    }
    int l,r;
    while (q--){
        cin>>l>>r;
        node x=T.query(rt[r],1,n,l,r);
        node y=T.query(rt[l-1],1,n,l,r);
        // cout<<x.x<<'#'<<x.y<<'\n';
        cout<<x.calc(r)-y.calc(l-1)<<'\n';
    }
    return 0;
}