#include<bits/stdc++.h>
using namespace std;
const int lim=100005;
typedef pair<int,int> pii;
typedef long long ll;
int n,q,rt[110000];
int a[110000],m[110000],k[110000];
struct Node{
    int l,r,t;
    Node(){}
    Node(int _l,int _r,int _t):l(_l),r(_r),t(_t){}
    bool operator<(const Node &a) const{ return l<a.l;}
};
struct node{
    ll k,b;
    node(){}
    node(ll _k,ll _b):k(_k),b(_b){}
    node operator+(const node &a) const{ return node(k+a.k,b+a.b);}
    node operator-(const node &a) const{ return node(k-a.k,b-a.b);}
};
struct SegmentTree{
    int cnt,ls[11000000],rs[11000000];
    node val[11000000];
    int Newnode(int now){
        cnt++;
        val[cnt]=val[now];
        ls[cnt]=ls[now]; rs[cnt]=rs[now];
        return cnt;
    }
    void change(int &now,int l,int r,int x,node v){
        now=Newnode(now); val[now]=val[now]+v;
        if (l==r) return;
        int mid=(l+r)>>1;
        if (x<=mid) change(ls[now],l,mid,x,v);
        else change(rs[now],mid+1,r,x,v);
    }
    node query(int now,int l,int r,int x){
        if (!now||x<=l) return val[now];
        int mid=(l+r)>>1;
        if (x<=mid) return query(ls[now],l,mid,x)+query(rs[now],mid+1,r,x);
        else return query(rs[now],mid+1,r,x);
    }
} T;
set<Node> s; ll sum[110000];
void update(int x){
    auto it=--s.upper_bound(Node(x,0,0));
    int l=it->l,r=it->r,t=it->t;
    if (l!=x){
        s.erase(it);
        s.insert(Node(l,x-1,t)); s.insert(Node(x,r,t));
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>m[i]>>k[i]; sum[i]=sum[i-1]+m[i];
        rt[i]=rt[i-1]; T.change(rt[i],0,lim,(k[i]?m[i]/k[i]:lim),node(k[i],-m[i]));
    }
    s.insert(Node(1,n,-1)); s.insert(Node(n+1,n+1,-1));
    cin>>q; int t,l,r;
    while (q--){
        cin>>t>>l>>r;
        update(l); update(r+1);
        auto it=s.lower_bound(Node(l,0,0));

        ll ans=0;
        while (it->l<=r){
            if (it->t==-1)
                for (int i=it->l;i<=it->r;i++) ans+=min(1ll*m[i],a[i]+1ll*k[i]*t);
            else{
                int x=min(lim,t-it->t);
                node res=T.query(rt[it->r],0,lim,x)-T.query(rt[it->l-1],0,lim,x);
                ans+=res.k*(t-it->t)+res.b+sum[it->r]-sum[it->l-1];
            }
            it=s.erase(it);
        }
        s.insert(Node(l,r,t));
        cout<<ans<<'\n';
    }
    return 0;
}