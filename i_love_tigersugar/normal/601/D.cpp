#include<bits/stdc++.h>
#define MAX   300300
#define NMOD   2
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int mod[]={(int)1e9+2277,(int)1e9+5277,(int)1e9+8277,(int)1e9+9277};
int base,baseInv[NMOD];
int pw[NMOD][MAX],pwInv[NMOD][MAX];
int inverse(int x,int mod) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void getBase(void) {
    srand(time(NULL));
    base=300+rand()%701;
    REP(j,NMOD) {
        baseInv[j]=inverse(base,mod[j]);
        pw[j][0]=pwInv[j][0]=1;
        FOR(i,1,MAX-1) {
            pw[j][i]=1LL*pw[j][i-1]*base%mod[j];
            pwInv[j][i]=1LL*pwInv[j][i-1]*baseInv[j]%mod[j];
        }
    }
}
struct Hash {
    int len,val[NMOD];
    Hash() {
        len=0;
        memset(val,0,sizeof val);
    }
    Hash(int c) {
        len=1;
        REP(i,NMOD) val[i]=c;
    }
    Hash operator + (const Hash &x) const {
        Hash res;
        res.len=len+x.len;
        REP(i,NMOD) res.val[i]=(x.val[i]+1LL*val[i]*pw[i][x.len])%mod[i];
        return (res);
    }
    Hash operator - (const Hash &x) const {
        Hash res;
        res.len=len-x.len;
        REP(i,NMOD)
            res.val[i]=1LL*(val[i]-x.val[i]+mod[i])%mod[i]*pwInv[i][x.len]%mod[i];
        return (res);
    }
    bool operator < (const Hash &x) const {
        if (len!=x.len) return (len<x.len);
        REP(i,NMOD) if (val[i]!=x.val[i]) return (val[i]<x.val[i]);
        return (false);
    }
};
vector<int> adj[MAX];
int val[MAX],diff[MAX];
char c[MAX];
Hash lazy[MAX];
set<Hash> *str[MAX];
int n;
void loadTree(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&val[i]);
    scanf("%s",c+1);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int u,int p) {
    int maxChild=-1;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        dfs(v,u);
        if (maxChild<0 || diff[maxChild]<diff[v]) maxChild=v;
    }
    if (maxChild<0) {
        str[u]=new set<Hash>();
        str[u]->insert(Hash(c[u]));
        lazy[u]=Hash();
        diff[u]=1;
        return;
    }
    str[u]=str[maxChild];
    lazy[u]=lazy[maxChild]+Hash(c[u]);
    FORE(it,adj[u]) if (*it!=p && *it!=maxChild) FORE(jt,*str[*it])
        str[u]->insert(*jt+lazy[*it]-lazy[maxChild]);
    str[u]->insert(Hash()-lazy[maxChild]);
    diff[u]=str[u]->size();
}
void process(void) {
    dfs(1,-1);
    int maxVal=diff[1]+val[1];
    int cntMax=1;
    FOR(i,2,n) {
        if (diff[i]+val[i]>maxVal) {
            maxVal=diff[i]+val[i];
            cntMax=1;
        } else if (diff[i]+val[i]==maxVal) cntMax++;
    }
    printf("%d\n%d\n",maxVal,cntMax);
}
int main(void) {
    getBase();
    loadTree();
    process();
    return 0;
}