#include<algorithm>
#include<cstdio>
#include<iostream>
#define MAX   1000100
#define NMOD    3
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int mod[]={(int)1e9+21,(int)1e9+7,(int)1e9+9,(int)1e9+33};
typedef pair<int,int> ii;
int pw[NMOD][MAX];
inline void add(int &x,const int &y,int mod) {
    x+=y;
    if (x>=mod) x-=mod;
}
struct hash {
    int v[NMOD];
    hash() {
        REP(i,NMOD) v[i]=0;
    }
    void addnum(int pos) {
        REP(i,NMOD) add(v[i],pw[i][pos],mod[i]);
    }
    bool operator < (const hash &h) const {
        REP(i,NMOD) if (v[i]!=h.v[i]) return (v[i]<h.v[i]);
        return (false);
    }
    bool operator == (const hash &h) const {
        REP(i,NMOD) if (v[i]!=h.v[i]) return (false);
        return (true);
    }
};
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
ii edge[MAX];
hash h[MAX];
int n,m;
int pos[MAX];
void init(void) {
    n=nextint();
    m=nextint();
    REP(j,NMOD) {
        pw[j][0]=1;
        FOR(i,1,n) {
            pw[j][i]=pw[j][i-1];
            add(pw[j][i],pw[j][i-1],mod[j]);
        }
    }
    REP(i,m) {
        int u=nextint();
        int v=nextint();
        edge[i]=ii(u,v);
        h[u].addnum(v);
        h[v].addnum(u);
    }
}
bool cmp(const int &x,const int &y) {
    return (h[x]<h[y]);
}
void process(void) {
    FOR(i,1,n) pos[i]=i;
    sort(pos+1,pos+n+1,cmp);
    long long res=0;
    int j=1;
    FOR(i,1,n) {
        if (i>1 && h[pos[i]]==h[pos[i-1]]) continue;
        res+=1LL*(i-j)*(i-j-1)>>1;
        j=i;
    }
    res+=1LL*(n-j+1)*(n-j)>>1;
    REP(i,m) {
        int u=edge[i].fi;
        int v=edge[i].se;
        hash hu=h[u];
        hash hv=h[v];
        hu.addnum(u);
        hv.addnum(v);
        if (hu==hv) res++;
    }
    cout<<res;
}
int main(void) {
    init();
    process();
    return 0;
}