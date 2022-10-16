#include<bits/stdc++.h>
#define MAX 80
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll mod=(ll)1e9+7LL;
struct matrix {
    int m,n;
    int d[88][88];
    matrix() {
        m=0;n=0;
        memset(d,0,sizeof d);       
    }
    void assign(int x,int y) {
        m=x;n=y;
    }
    void operator = (const matrix &x) {
        m=x.m;
        n=x.n;
        REP(i,m) REP(j,n) d[i][j]=x.d[i][j];
    }
    matrix operator * (const matrix &a) const {
        matrix res;
        int x=m;
        int y=n;
        int z=a.n;
        res.m=x;
        res.n=z;
        REP(i,x) REP(j,z) {
            res.d[i][j]=0;
            REP(k,y) res.d[i][j]=(res.d[i][j]+1LL*d[i][k]*a.d[k][j])%mod;
        }
        return (res);
    }
    matrix operator ^ (ll k) const {
        assert(m==n);
        matrix res;
        matrix mul=*this;
        res.m=m;
        res.n=n;
        REP(i,m) REP(j,n) res.d[i][j]=(i==j);
        while (k>0) {
            if (k%2==1) res=res*mul;
            mul=mul*mul;
            k=k>>1;
        }
        return (res);
    }
};
int k;
ll n;
int c[MAX][MAX];
matrix fst,mul;
void process(void) {
    cin >> n >> k;
    FOR(i,1,k+3) {
        c[i][0]=0;
        c[0][i]=1;
    }
    c[0][0]=1;
    FOR(i,1,k+3) FOR(j,1,k+3) {
        if (i>j) c[i][j]=0;
        if (i==j) c[i][j]=1;
        if (i<j) c[i][j]=(c[i-1][j-1]+c[i][j-1])%mod;
    }
    fst.assign(1,2*k+3);
    mul.assign(2*k+3,2*k+3);
    REP(i,k+1) REP(j,k+1) mul.d[i][j]=0;
    REP(i,k+1) FOR(j,k+1,2*k+1) {
        int j1=j-k-1;
        if (i>j1) mul.d[i][j]=0; else mul.d[i][j]=c[i][j1];
    }
    FOR(i,k+1,2*k+1) REP(j,k+1) {
        int i1=i-k-1;
        if (i1>j) mul.d[i][j]=0; else mul.d[i][j]=c[i1][j];
    }
    FOR(i,k+1,2*k+1) FOR(j,k+1,2*k+1) {
        int i1=i-k-1;
        int j1=j-k-1;
        if (i1>j1) mul.d[i][j]=0; else mul.d[i][j]=c[i1][j1];
    }
    REP(i,2*k+3) {
        mul.d[2*k+2][i]=0;
        mul.d[i][2*k+2]=0;
    }
    mul.d[2*k+2][2*k+2]=1;
    mul.d[2*k+1][2*k+2]=1;
    REP(i,2*k+2) fst.d[0][i]=1;
    fst.d[0][2*k+2]=0;
    fst=fst*(mul^n);
    cout << fst.d[0][2*k+2];
}
int main(void) {
    process();
    return 0;
}