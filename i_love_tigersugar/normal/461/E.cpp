#include<cstdio>
#include<cstring>
#include<iostream>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FOUR(i) (1<<(2*(i)))
#define LET(x,i) (((x)>>(2*(i)))&3)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
template<class T>
    inline void minimize(T &x,const T &y) {
        if (x>y) x=y;
    }
struct matrix {
    int m,n;
    ll d[7][7];
    matrix() {
        m=n=0;
        memset(d,0,sizeof d);
    }
    matrix(int m,int n) {
        this->m=m;
        this->n=n;
        memset(d,0,sizeof d);
    }
    matrix operator * (const matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        matrix res=matrix(x,z);
        memset(res.d,0x3f,sizeof res.d);
        REP(i,x) REP(j,y) REP(k,z) minimize(res.d[i][k],d[i][j]+a.d[j][k]);
        return (res);
    }
};
string s;
bool ex[FOUR(10)+7];
int dis[7][7];
ll len;
int n;
void getsub(int x) {
    memset(ex,false,sizeof ex);
    REP(i,n-x+1) {
        int code=0;
        REP(j,x) code=(code<<2)|(s[i+j]-'A');
        ex[code]=true;
    }
    REP(i,FOUR(x)) if (!ex[i]) {
        int f=LET(i,x-1);
        int l=LET(i,0);
        minimize(dis[f][l],x-1);
    }
}
void init(void) {
    cin>>len>>s;
    n=s.size();
    memset(dis,0x3f,sizeof dis);
    FOR(i,2,10) getsub(i);
}
ll minlen(ll x) {
    if (x==0) return (0);
    matrix res=matrix(4,4);
    matrix mul=matrix(4,4);
    REP(i,4) REP(j,4) mul.d[i][j]=dis[i][j];
    x--;
    while (x>0) {
        if (x&1) res=res*mul;
        mul=mul*mul;
        x>>=1;
    }
    ll len=INF;
    REP(i,4) REP(j,4) minimize(len,res.d[i][j]);
    return (len+1);
}
void process(void) {
    ll l=0;
    ll r=INF;
    while (true) {
        if (r==l) {
            cout<<r;
            return;
        }
        if (r-l==1) {
            if (minlen(r)<=len) cout<<r; else cout<<l;
            return;
        }
        ll m=(l+r)>>1;
        if (minlen(m)<=len) l=m; else r=m-1;
    }
}
int main(void) {
    init();
    process();
    return 0;
}