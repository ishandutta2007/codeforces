#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=210000;
const int blo=320;
int n,q,a[MAXN],val[MAXN],num[MAXN],vis[MAXN],fa[MAXN],dep[MAXN];
int cnt,L[MAXN],R[MAXN],seq[MAXN],bel[MAXN],tot[2][MAXN]; ll ans,Ans[MAXN];
vector<int> vec[MAXN];
void dfs(int u,int f){
    L[u]=++cnt; fa[u]=f; dep[u]=dep[f]+1;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u);
    }
    R[u]=++cnt;
}
struct Query{
    int l,r,id,lca;
    Query(){}
    Query(int _l,int _r,int _id,int _lca):l(_l),r(_r),id(_id),lca(_lca){}
    bool operator<(const Query &a) const{
        return bel[l]<bel[a.l]||bel[l]==bel[a.l]&&r<a.r;
    }
} que[MAXN];
int mn[21][MAXN],Log2[MAXN];
void add(int x){
    if (vis[x]){
        tot[a[x]][val[x]]--;
        ans-=tot[a[x]^1][val[x]];
    } else{
        tot[a[x]][val[x]]++;
        ans+=tot[a[x]^1][val[x]];
    }
    vis[x]^=1;
}
void init_rmq(){
    Log2[0]=-1;
    for (int i=1;i<=(n<<1);i++){
        Log2[i]=Log2[i>>1]+1;
        mn[0][i]=seq[i];
    }
    for (int j=1;j<=20;j++)
        for (int i=1;i+(1<<j)-1<=(n<<1);i++)
            if (dep[mn[j-1][i]]<dep[mn[j-1][i+(1<<(j-1))]]) mn[j][i]=mn[j-1][i];
            else mn[j][i]=mn[j-1][i+(1<<(j-1))];
}
int query_rmq(int l,int r){
    int k=Log2[r-l+1];
    if (dep[mn[k][l]]<dep[mn[k][r-(1<<k)+1]]) return mn[k][l];
    else return mn[k][r-(1<<k)+1];
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&val[i]),num[i]=val[i];
    sort(num+1,num+n+1); int cnt=unique(num+1,num+n+1)-num-1;
    for (int i=1;i<=n;i++) val[i]=lower_bound(num+1,num+cnt+1,val[i])-num;
    int u,v;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) seq[L[i]]=i,seq[R[i]]=i;
    for (int i=1;i<=(n<<1);i++) bel[i]=(i-1)/blo;
    scanf("%d",&q); init_rmq();
    for (int i=1;i<=q;i++){
        scanf("%d%d",&u,&v);
        if (L[u]>L[v]) swap(u,v);
        if (L[u]<=L[v]&&R[v]<=R[u]) que[i]=Query(L[u],L[v],i,0);
        else que[i]=Query(R[u],L[v],i,fa[query_rmq(R[u],L[v])]);
    }
    sort(que+1,que+q+1);
    int l=1,r=0;
    for (int i=1;i<=q;i++){
        Query u=que[i];
        while (l>u.l) add(seq[--l]);
        while (r<u.r) add(seq[++r]);
        while (l<u.l) add(seq[l++]);
        while (r>u.r) add(seq[r--]);
        if (u.lca) add(u.lca);
        Ans[u.id]=ans;
        if (u.lca) add(u.lca);
    }
    for (int i=1;i<=q;i++) printf("%lld\n",Ans[i]);
    return 0;
}