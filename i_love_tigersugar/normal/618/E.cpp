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
#define SQR(x) (1.0*(x)*(x))
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
const double PI=acos(-1.0);
const double eps=1e-13;
struct Matrix {
    int m,n;
    double d[2][2];
    Matrix() {
        m=n=0;
        REP(i,2) REP(j,2) d[i][j]=0;
    }
    Matrix(int m,int n) {
        this->m=m;
        this->n=n;
        REP(i,m) REP(j,n) d[i][j]=0;
    }
    Matrix operator + (const Matrix &a) const {
        Matrix res(m,n);
        REP(i,m) REP(j,n) res.d[i][j]=d[i][j]+a.d[i][j];
        return (res);
    }
    Matrix operator * (const Matrix &a) const {
        int x=m;
        int y=n;
        int z=a.n;
        Matrix res(x,z);
        REP(i,x) REP(j,y) REP(k,z) res.d[i][k]+=d[i][j]*a.d[j][k];
        return (res);
    }
};
Matrix element(int n) {
    Matrix res(n,n);
    REP(i,n) REP(j,n) res.d[i][j]=i==j?1.0:0.0;
    return (res);
}
class SegmentTree {
    private:
    vector<Matrix> tree,lazy;
    int n;
    void build(int i,int l,int r) {
        lazy[i]=element(2);
        if (l==r) {
            REP(j,2) tree[i].d[0][j]=1.0-j;
            return;
        }
        int m=(l+r)>>1;
        build(2*i,l,m);
        build(2*i+1,m+1,r);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    void pushDown(int i) {
        REP(j,2) {
            tree[2*i+j]=tree[2*i+j]*lazy[i];
            lazy[2*i+j]=lazy[2*i+j]*lazy[i];
        }
        lazy[i]=element(2);
    }
    void update(int i,int l,int r,int u,int v,const Matrix &c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[i]=tree[i]*c;
            lazy[i]=lazy[i]*c;
            return;
        }
        pushDown(i);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    Matrix get(int i,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return (Matrix(1,2));
        if (u<=l && r<=v) return (tree[i]);
        pushDown(i);
        int m=(l+r)>>1;
        Matrix L=get(2*i,l,m,u,v);
        Matrix R=get(2*i+1,m+1,r,u,v);
        return (L+R);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,Matrix(1,2));
        lazy.assign(4*n+7,Matrix(2,2));
        build(1,1,n);
    }
    void translate(int x,double l) {
        Matrix cur=get(1,1,n,x,x);
        double curLen=sqrt(SQR(cur.d[0][0])+SQR(cur.d[0][1])+eps);
        double rate=1.0+l/curLen;
        Matrix tmp(2,2);
        REP(i,2) REP(j,2) tmp.d[i][j]=i==j?rate:0.0;
        update(1,1,n,x,x,tmp);
    }
    void rotate(int l,int r,double angle) {
        Matrix tmp(2,2);
        tmp.d[0][0]=cos(angle);
        tmp.d[0][1]=sin(angle);
        tmp.d[1][0]=-sin(angle);
        tmp.d[1][1]=cos(angle);
        update(1,1,n,l,r,tmp);
    }
    pair<double,double> result(void) {
        Matrix tmp=get(1,1,n,1,n);
        return (make_pair(tmp.d[0][0],tmp.d[0][1]));
    }
};
void process(void) {
    int n,q;
    scanf("%d%d",&n,&q);
    SegmentTree myit(n);
    REP(love,q) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (x==1) myit.translate(y,z);
        else myit.rotate(y,n,-PI*z/180);
        pair<double,double> tmp=myit.result();
        printf("%.11lf %.11lf\n",tmp.fi,tmp.se);
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    process();
    return 0;
}