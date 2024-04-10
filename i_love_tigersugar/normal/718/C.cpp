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
const int mod=(int)1e9+7;
struct Matrix {
    int d[2][2];
    int m, n;
    Matrix() {
        m = n = 0;
        memset(d, 0, sizeof d);
    }
    Matrix(int _m, int _n) {
        m = _m; n = _n;
        memset(d, 0, sizeof d);
    }
    Matrix operator + (const Matrix &a) const {
        Matrix res(m,n);
        REP(i,m) REP(j,n) res.d[i][j]=(d[i][j]+a.d[i][j])%mod;
        return res;
    }
    Matrix operator * (const Matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        Matrix res(x,z);
        REP(i,x) REP(j,y) REP(k,z) res.d[i][k]=(res.d[i][k]+1LL*d[i][j]*a.d[j][k])%mod;
        return res;
    }
    Matrix operator ^ (int k) const {
        Matrix res(n, n);
        Matrix mul = *this;
        REP(i, n) REP(j, n) res.d[i][j]=i==j;
        while (k>0) {
            if (k&1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }
};
Matrix unitMatrix(int n) {
    Matrix res(n, n);
    REP(i, n) REP(j, n) res.d[i][j] = i == j ? 1 : 0;
    return res;
}
Matrix fibMul;
class SegmentTree {
    private:
    vector<Matrix> tree, lazy;
    int n;
    void pushDown(int i) {
        FOR(j, 2 * i, 2 * i + 1) {
            lazy[j] = lazy[j] * lazy[i];
            tree[j] = tree[j] * lazy[i];
        }
        lazy[i] = unitMatrix(2);
    }
    void update(int i,int l,int r,int u,int v,const Matrix &c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            tree[i] = tree[i] * c;
            lazy[i] = lazy[i] * c;
            return;
        }
        pushDown(i);
        int m = (l + r) / 2;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    Matrix get(int i,int l,int r,int u,int v) {
        if (l > v || r < u || l > r || v < u) return Matrix(1,2);
        if (u <= l && r <= v) return tree[i];
        pushDown(i);
        int m = (l + r) / 2;
        Matrix L = get(2*i,l,m,u,v);
        Matrix R = get(2*i+1,m+1,r,u,v);
        return L + R;
    }
    public:
    SegmentTree(int n = 0) {
        this->n = n;
        if (n > 0) {
            tree.assign(4 * n + 7, Matrix(1, 2));
            lazy.assign(4 * n + 7, unitMatrix(2));
            FORE(it, tree) {
                it->d[0][0] = 0;
                it->d[0][1] = 1;
            }
        }
    }
    void update(int l, int r, int c) {
        update(1, 1, n, l, r, fibMul ^ c);
    }
    int get(int l, int r) {
        return get(1, 1, n, l, r).d[0][0];
    }
};
void process(void) {
    fibMul = Matrix(2, 2);
    fibMul.d[0][1] = fibMul.d[1][0] = fibMul.d[1][1] = 1;
    int n, q; scanf("%d%d", &n, &q);
    SegmentTree myit(n);
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        myit.update(i, i, x);
    }
    REP(love, q) {
        int t, l, r, c; scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            scanf("%d ", &c);
            myit.update(l, r, c);
        } else printf("%d\n", myit.get(l, r));
    }
}
int main(void) {
    process();
    return 0;
}