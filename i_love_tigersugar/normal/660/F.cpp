#include<bits/stdc++.h>
#define MAX   200200
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
#define __builtin_popcount __builtin_popcountll
using namespace std;
const long long INF=(long long)1e18+7LL;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
long long ceil(long long a,long long b) {
    assert(b!=0);
    if (b<0) return (ceil(-a,-b));
    assert(a>=0);
    return (a/b+(a%b>0));
}
class ConvexHull {
    private:
    struct Line {
        int x;
        long long a,b;
        Line() {
            x=a=b=0;
        }
        Line(long long _x,long long _a,long long _b) {
            x=_x;a=_a;b=_b;
        }
        bool operator < (const Line &l) const {
            return (x<l.x);
        }
        long long value(void) const {
            return (a*x+b);
        }
    };
    vector<Line> lines;
    vector<pair<long long,long long> > toAdd;
    void addLine(long long a,long long b) {
        while (!lines.empty() && lines.back().value()<=lines.back().x*a+b) lines.pop_back();
        if (lines.empty()) {
            lines.push_back(Line(0,a,b));
            return;
        }
        long long prevA=lines.back().a;
        long long prevB=lines.back().b;
        long long inter=ceil(prevB-b,a-prevA);
        if (inter>MAX) return;
        lines.push_back(Line(inter,a,b));
    }
    public:
    ConvexHull() {}
    void addQuery(long long a,long long b) {
        toAdd.push_back(make_pair(a,b));
    }
    void processLine(void) {
        sort(ALL(toAdd));
        FORE(it,toAdd) addLine(it->fi,it->se);
    }
    long long findMax(int x) const {
        int id=upper_bound(ALL(lines),Line(x,x,x))-lines.begin()-1;
        return (lines[id].a*x+lines[id].b);
    }
};
class SegmentTree {
    private:
    vector<ConvexHull> tree;
    int n;
    void build(long long sum[],long long val[],int i,int l,int r) {
        FOR(j,l,r) tree[i].addQuery(-sum[j],val[j]);
        tree[i].processLine();
        if (l<r) {
            int m=(l+r)>>1;
            build(sum,val,2*i,l,m);
            build(sum,val,2*i+1,m+1,r);
        }
    }
    long long query(int i,int l,int r,int u,int v,int x) const {
        if (l>v || r<u || l>r || v<u) return (-INF);
        if (u<=l && r<=v) return (tree[i].findMax(x));
        int m=(l+r)>>1;
        long long L=query(2*i,l,m,u,v,x);
        long long R=query(2*i+1,m+1,r,u,v,x);
        return (max(L,R));
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n,long long sum[],long long val[]) {
        this->n=n;
        tree.assign(4*n+7,ConvexHull());
        build(sum,val,1,1,n);
    }
    long long query(int x,int l,int r) const {
        return (query(1,1,n,l,r,x));
    }
};
int a[MAX],n;
long long sum[MAX],val[MAX];
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) {
        sum[i]=sum[i-1]+a[i];
        val[i]=val[i-1]+1LL*a[i]*i;
    }
    SegmentTree myit(n,sum,val);
    long long res=-INF;
    FOR(i,0,n-1) maximize(res,myit.query(i,i+1,n)-val[i]+sum[i]*i);
    cout<<max(res,0LL)<<endl;
}
int main(void) {
    process();
    return 0;
}