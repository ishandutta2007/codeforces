#include<bits/stdc++.h>
#define MAX   300303
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
void add(int &x,const int &y) {
    x=(x+y)%mod;
}
class IT {
    public:
    vector<int> sum,sumh;
    int n;
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        sum=vector<int>(4*n+7,0);
        sumh=vector<int>(4*n+7,0);
    }
    void update(vector<int> &t,int i,int l,int r,int u,int v,int c) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            add(t[i],c);
            return;
        }
        int m=(l+r)/2;
        update(t,2*i,l,m,u,v,c);
        update(t,2*i+1,m+1,r,u,v,c);
    }
    int get(int p,int x) {
        int s=0;
        int sh=0;
        int i=1;
        int l=1;
        int r=n;
        while (true) {
            add(s,sum[i]);
            add(sh,sumh[i]);
            if (l==r) return ((s-1LL*x*sh%mod+mod)%mod);
            int m=(l+r)/2;
            if (p>m) {
                i=2*i+1;
                l=m+1;
            }
            else {
                i=2*i;
                r=m;
            }
        }
    }
    void query(int l,int r,int s,int h) {
        update(sum,1,1,n,l,r,s);
        update(sumh,1,1,n,l,r,h);
    }
};
IT it;
vector<int> g[MAX];
int h[MAX],sta[MAX],fin[MAX],p[MAX];
int n,cnt;
void loadtree(void) {
    scanf("%d",&n);
    FOR(i,2,n) {
        int u,v;
        scanf("%d",&v);
        u=i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void dfs(int u) {
    cnt++;
    sta[u]=cnt;
    FORE(it,g[u]) if (*it!=p[u]) {
        int v=*it;
        h[v]=h[u]+1;
        p[v]=u;
        dfs(v);
    }
    fin[u]=cnt;
}
void process(void) {
    dfs(1);
    it=IT(n);
    int q;
    scanf("%d",&q);
    REP(zz,q) {
        int t,u;
        scanf("%d%d",&t,&u);
        if (t==1) {
            int x,k;
            scanf("%d%d",&x,&k);
            it.query(sta[u],fin[u],(x+1LL*k*h[u]%mod)%mod,k);
        }
        else printf("%d\n",it.get(sta[u],h[u]));
    }
}
int main(void) {
    loadtree();
    process();
    return 0;
}