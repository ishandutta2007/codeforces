#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
typedef long long ll;
const ll INF=(ll)1e9+7;
ll s[MAX];
ll k[MAX];
int nc[MAX];
vector<int> g[MAX];
int n;
int c[MAX];
ll min(const ll &x,const ll &y) {
    if (x<y) return (x); else return (y);
}
ll gcd(ll a,ll b) {
    while (true) {
        if (a==0LL) return (b);
        if (b==0LL) return (a);
        if (a%b==0) return (b);
        if (b%a==0) return (a);
        if (a>b) a=a%b; else b=b%a;
    }
}
ll lcm(const ll &a,const ll &b) {
    if (a>=INF) return (INF);
    if (b>=INF) return (INF);
    return (a*b/gcd(a,b));
}
void loadtree(void) {
    scanf("%d",&n);
    int i,u,v;
    for (i=1;i<=n;i=i+1) scanf("%I64d",&s[i]);
    for (i=1;i<n;i=i+1) {
        scanf("%d",&u);
        scanf("%d",&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void visit(const int &u) {
    //printf("Visiting %d\n",u);
    int i,v;    
    nc[u]=0;
    ll t=1LL;
    for (i=0;i<g[u].size();i=i+1) {
        v=g[u][i];
        if (c[v]==0) {
            nc[u]++;
            c[v]=1;
            visit(v);
            s[u]+=s[v];
            t=lcm(t,k[v]);
        }
    }
    if (nc[u]==0) k[u]=1LL;
    else {
        if (t*nc[u]>=INF) k[u]=INF;
        else k[u]=t*nc[u];  
    }   
    //printf("Properties of %d is k=%I64d, s=%I64d\n",u,k[u],s[u]);
}
void DFS(const int &u) {
    int i,v;
    for (i=0;i<g[u].size();i=i+1) {
        v=g[u][i];
        if (c[v]==0) {
            c[v]=1;
            k[v]=k[u]/nc[u];
            DFS(v);
        }
    }
}
void process(void) {
    //printf("DFS123\n");
    memset(c,0,sizeof c);
    c[1]=1;
    visit(1);
    int i;
    for (i=1;i<=n;i=i+1)
        if (k[i]>=INF) {
            printf("%I64d",s[1]);
            exit(0);
        }   
    //printf("DFS123\n");
    memset(c,0,sizeof c);
    c[1]=1;
    DFS(1);
    ll tmp=INF;
    for (i=1;i<=n;i=i+1) tmp=min(tmp,s[i]/k[i]);
    printf("%I64d",s[1]-k[1]*tmp);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    loadtree();
    process();
    return 0;
}