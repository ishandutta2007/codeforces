#include<bits/stdc++.h>
#define MAX   222
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
const int mod=(int)1e9+7;
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
        REP(i,n) REP(j,n) res.d[i][j]=i==j;
        Matrix mul=*this;
        while (k>0) {
            if (k&1) res=res*mul;
            mul=mul*mul;
            k>>=1;
        }
        return (res);
    }
};
long long a[MAX],k;
int n;
void init(void) {
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
}
void process(void) {
    vector<long long> val;
    FOR(i,1,n) val.push_back(a[i]);
    sort(ALL(val));
    //val.resize(unique(ALL(val))-val.begin());
    n=val.size();
    Matrix fst(1,n);
    Matrix mul(n,n);
    REP(i,n) fst.d[0][i]++;
    REP(i,n) REP(j,n) if (__builtin_popcount(val[i]^val[j])%3==0) mul.d[i][j]++;
    fst=fst*(mul^(k-1));
    int res=0;
    REP(i,n) res=(res+fst.d[0][i])%mod;
    assert(0<=res && res<mod);
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}