#include<cstdio>
#include<vector>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
class DSU {
    int n;
    vector<int> up;
    int find(int x) {
        if (up[x]<0) return (x);
        up[x]=find(up[x]);
        return (up[x]);
    }
    void join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return;
        up[y]=x;
    }
    public:
    DSU() {
        n=0;
    }
    DSU(int n) {
        this->n=n;
        up.assign(2*n+7,-1);
    }
    void add(int l,int r,int k) {
        REP(i,2) join(2*l+i,2*r+(i^k));
    }
    int count(void) {
        REP(i,n+1) if (find(2*i)==find(2*i+1)) return (0);
        int cnt=0;
        REP(i,2*n+2) if (up[i]<0) cnt++;
        int res=1;
        REP(zz,(cnt-2)/2) res=2*res%mod;
        return (res);
    }
};
inline int Abs(int x) {
    return (x<0?-x:x);
}
inline int ceil(int x,int y) {
    return (x/y+(x%y>0));
}
int n,m;
DSU dsu[2];
void process(void) {
    scanf("%d%d",&n,&m);
    REP(i,2) dsu[i]=DSU(n);
    FOR(i,1,n) dsu[(i+1)&1].add(i-1,i,0);
    REP(zz,m) {
        int x,y;
        char c;
        scanf("%d%d %c",&x,&y,&c);
        int L=Abs(x-y)+1;
        int R=min(x+y-1,2*n+1-(x+y));
        dsu[(x+y+1)&1].add(L-1,R,c=='o');
    }
    printf("%d",1LL*dsu[0].count()*dsu[1].count()%mod);
}
int main(void) {
    process();
    return 0;
}