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
const double eps=7e-5;
const pair<double,double> NA(-1.0,-1.0);
class SegmentTree {
    private:
    int n;
    vector<pair<double,double> > tree;
    static pair<double,double> concat(const pair<double,double> &left,const pair<double,double> &right) {
        if (left.fi<0) return (right);
        if (right.fi<0) return (left);
        double A=right.fi/(1.0-left.se+right.fi*left.se);
        double B=right.fi*left.se/(1.0-left.se+right.fi*left.se);
        double f=left.fi*A;
        double g=right.se+(1.0-right.se)*B;
        return (make_pair(f,g));
    }
    void update(int i,int l,int r,int x,double v) {
        if (l==r) {
            tree[i]=make_pair(v,v);
            return;
        }
        int m=(l+r)>>1;
        if (x>m) update(2*i+1,m+1,r,x,v);
        else update(2*i,l,m,x,v);
        tree[i]=concat(tree[2*i],tree[2*i+1]);
    }
    pair<double,double> get(int i,int l,int r,int u,int v) const {
        if (l>v || r<u || l>r || v<u) return (NA);
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        pair<double,double> L=get(2*i,l,m,u,v);
        pair<double,double> R=get(2*i+1,m+1,r,u,v);
        return (concat(L,R));
    }
    public:
    SegmentTree(int n=0) {
        this->n=n;
        if (n>0) tree.assign(4*n+7,NA);
    }
    void update(int x,double v) {
        update(1,1,n,x,v);
    }
    double get(int l,int r) const {
        return (get(1,1,n,l,r).fi);
    }
};
void process(void) {
    int n,q; scanf("%d%d",&n,&q);
    SegmentTree myit(n);
    FOR(i,1,n) {
        int a,b; scanf("%d%d",&a,&b);
        myit.update(i,1.0*a/b);
    }
    cerr<<"DONE"<<endl;
    REP(love,q) {
        int type; scanf("%d",&type);
        if (type==1) {
            int x,a,b; scanf("%d%d%d",&x,&a,&b);
            myit.update(x,1.0*a/b);
        } else {
            int l,r; scanf("%d%d",&l,&r);
            printf("%.7lf\n",myit.get(l,r));
        }
    }
}
int main(void) {
    process();
    return 0;
}