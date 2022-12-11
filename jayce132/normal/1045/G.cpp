#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int N=1e5+10;
const int mod=0;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
template<typename T> bool chkmax(T &a,T b) { return a<b?a=b,1:0; };
template<typename T> bool chkmin(T &a,T b) { return a>b?a=b,1:0; };
int add(int a,int b) { return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b) { return a-b<0?a-b+mod:a-b; }
void inc(int &a,int b) { a=(a+b>=mod?a+b-mod:a+b); }
void dec(int &a,int b) { a=(a-b<0?a-b+mod:a-b); }
int n,k;
struct data { int x,r,q; } a[N];
bool operator<(data a,data b) {
    return a.r>b.r;
}
int tot=0,rt[N],tr[N*50],ls[N*50],rs[N*50];
void insert(int &o,int l,int r,int p,int v) {
    if(!o) o=++tot; tr[o]+=v;
    if(l==r) return; int mid=(l+r)>>1;
    if(p<=mid) insert(ls[o],l,mid,p,v);
    else insert(rs[o],mid+1,r,p,v);
}
int query(int o,int l,int r,int L,int R) {
    if(L<=l&&r<=R) return tr[o];
    int mid=(l+r)>>1,ret=0;
    if(L<=mid) ret+=query(ls[o],l,mid,L,R);
    if(R>mid) ret+=query(rs[o],mid+1,r,L,R);
    return ret;
}
int sx[N],tx=0,sq[N],tq=0;
int main() {
#ifndef ONLINE_JUDGE
    freopen("CF1045G.in","r",stdin);
    freopen("CF1045G.out","w",stdout);
#endif
    cin>>n>>k;
    for(int i=1;i<=n;i++) a[i].x=gi(),a[i].r=gi(),a[i].q=gi(),sx[++tx]=a[i].x,sq[++tq]=a[i].q;
    sort(a+1,a+n+1);
    sort(sx+1,sx+tx+1);tx=unique(sx+1,sx+tx+1)-sx-1;
    sort(sq+1,sq+tq+1);tq=unique(sq+1,sq+tq+1)-sq-1;
    sq[0]=-inf;sq[tq+1]=inf+inf;
    ll ans=0;
    for(int i=1;i<=n;i++) {
        int l=lower_bound(sx+1,sx+tx+1,a[i].x-a[i].r)-sx;
        int r=upper_bound(sx+1,sx+tx+1,a[i].x+a[i].r)-sx-1;
        int L=lower_bound(sq+1,sq+tq+1,a[i].q)-sq,R=L,q=L;
        int p=lower_bound(sx+1,sx+tx+1,a[i].x)-sx;
        while(a[i].q-sq[L-1]<=k) L--;
        while(sq[R+1]-a[i].q<=k) R++;
        for(int j=L;j<=R;j++) ans+=query(rt[j],1,tx,l,r);
        insert(rt[q],1,tx,p,1);
    }
    printf("%lld\n",ans);
    return 0;
}