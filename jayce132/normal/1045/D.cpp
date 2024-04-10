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
int n,q,du[N],fa[N];
double V,E,a[N],tag[N],sum[N];
vector<int> G[N];
void dfs(int u,int ff) {
    fa[u]=ff;
    for(int v:G[u]) if(v!=ff) dfs(v,u);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("CF1045D.in","r",stdin);
    freopen("CF1045D.out","w",stdout);
#endif
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]),a[i]=1-a[i];
    for(int i=1,u,v;i<n;i++) u=gi()+1,v=gi()+1,G[u].pb(v),G[v].pb(u);
    dfs(1,0);
    for(int i=1;i<=n;i++) V+=a[i];
    for(int u=1;u<=n;u++) {
        for(int v:G[u]) sum[u]+=a[v];
        E+=a[u]*sum[u];
    }
    cin>>q;
    while(q--) {
        int x=gi()+1;double y;scanf("%lf",&y);y=1-y;
        V+=y-a[x];
        E-=2*(sum[x]+tag[fa[x]])*a[x];
        tag[x]+=y-a[x];if(fa[x]) sum[fa[x]]+=y-a[x];
        a[x]=y;
        E+=2*(sum[x]+tag[fa[x]])*a[x];
        printf("%.5lf\n",V-E/2);
    }
    return 0;
}