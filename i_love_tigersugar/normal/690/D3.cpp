#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int mod=(int)1e6+3;
struct Matrix {
    int m,n;
    vector<vector<int> > d;
    Matrix() {
        m=n=0;
    }
    Matrix(int m,int n) {
        this->m=m;
        this->n=n;
        d.assign(m,vector<int>(n,0));
    }
    Matrix operator * (const Matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        Matrix res(x,z);
        REP(i,x) REP(j,y) REP(k,z) res.d[i][k]=(res.d[i][k]+1LL*d[i][j]*a.d[j][k])%mod;
        return (res);
    }
    Matrix operator ^ (long long k) const {
        Matrix res(n,n);
        Matrix mul=*this;
        REP(i,n) REP(j,n) res.d[i][j]=i==j;
        while (k>0) {
            if (k&1) res=res*mul;
            mul=mul*mul;
            k>>=1;
        }
        return (res);
    }
};
int solve(int c,int w,int h) {
    Matrix res(1,w+1);
    res.d[0][0]=1;
    Matrix mul(w+1,w+1);
    REP(i,w+1) {
        mul.d[i][0]=1;
        if (i+1<=w) mul.d[i][i+1]=h;
    }
    res=res*(mul^c);
    int sum=0;
    REP(i,w+1) sum=(sum+res.d[0][i])%mod;
    return (sum);
}
int main(void) {
    int c,w,h; scanf("%d%d%d",&c,&w,&h);
    printf("%d\n",solve(c,w,h));
    return 0;
}