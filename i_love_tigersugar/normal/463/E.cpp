#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<ctime>
#include<iostream>
#define MAXV   2002002
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define MASK(i) (1<<(i))
using namespace std;
clock_t start;
const double TL=9.7;
inline bool TLE(void) {
    return (clock()-start>TL*CLOCKS_PER_SEC);
}
class BIT {
    private:
    int n;
    map<int,int> v;
    void update(int x,int d) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.clear();
    }
    int get(int x) {
        if (x<1 || x>n) return (0);
        int res=0;
        for (;x>=1;x&=x-1)
            if (v.find(x)!=v.end()) res+=v[x];
        return (res);
    }
    void change(int l,int r,int x) {
        update(l,x);
        update(r+1,-x);
    }
};
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int notprime[MAXV];
int a[MAX];
vector<int> g[MAX];
int n,q,np,cnt;
int sta[MAX],fin[MAX],h[MAX];
int p[MAX][18];
BIT bit[MAXV];
void eratosthene(void) {
    REP(i,2) notprime[i]=1;
    FOR(i,2,MAXV-1) if (notprime[i]==0) {
        notprime[i]=-np; np++;
        for (int j=2*i;j<MAXV;j=j+i) notprime[j]=1;
    }
}
void loadtree(void) {
    n=nextint();
    q=nextint();
    FOR(i,1,n) a[i]=nextint();
    REP(zz,n-1) {
        int u=nextint();
        int v=nextint();
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,g[u]) if (*it!=p[u][0]) {
        int v=*it;
        p[v][0]=u;
        h[v]=h[u]+1;
        dfs(v);
    }
    fin[u]=cnt;
}
void setupLCA(void) {
    dfs(1);
    FOR(j,1,17) FOR(i,1,n) p[i][j]=p[p[i][j-1]][j-1];
}
void getdiv(int x,vector<int> &v) {
    for (int i=1;1LL*i*i<=x;i=i+1) if (x%i==0) {
        if (notprime[i]<=0) v.push_back(-notprime[i]);
        if (1LL*i*i==x) continue;
        if (notprime[x/i]<=0) v.push_back(-notprime[x/i]);
    }
}
void build(void) {
    REP(i,np) bit[i]=BIT(n);
    FOR(i,1,n) {
        vector<int> v;
        getdiv(a[i],v);
        FORE(it,v) bit[*it].change(sta[i],fin[i],1);
    }
}
int query(int u,int id) {
    int tmp=bit[id].get(sta[p[u][0]]);
    if (tmp==0) return (-1);
    FORD(i,17,0) if (MASK(i)<=h[u]) {
        if (bit[id].get(sta[p[u][i]])==tmp) u=p[u][i];
    }
    return (u);
}
int query(int u) {
    vector<int> v;
    getdiv(a[u],v);
    int res=-1;
    FORE(it,v) {
        int tmp=query(u,*it);
        if (tmp>0 && (res<0 || h[res]<h[tmp])) res=tmp;
    }
    return (res);
}
void process(void) {
    build();
    REP(zz,q) {
        if (nextint()==1) printf("%d\n",query(nextint()));
        else {
            int u=nextint();
            vector<int> v;
            getdiv(a[u],v);
            FORE(it,v) bit[*it].change(sta[u],fin[u],-1);
            a[u]=nextint();
            v.clear();
            getdiv(a[u],v);
            FORE(it,v) bit[*it].change(sta[u],fin[u],1);
        }
    }
    while (!TLE()) cerr<<3<<endl;
}
int main(void) {
    start=clock();
    eratosthene();
    loadtree();
    setupLCA();
    process();
    return 0;
}