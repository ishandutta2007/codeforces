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
class SegmentTree {
    private:
    vector<long long> sum;
    vector<int> maxVal,lazy;
    int n;
    void pushDown(int i,int l,int r) {
        int m=(l+r)>>1;
        if (lazy[i]>=0) {
            maxVal[2*i]=maxVal[2*i+1]=lazy[i];
            lazy[2*i]=lazy[2*i+1]=lazy[i];
            sum[2*i]=1LL*(m-l+1)*lazy[i];
            sum[2*i+1]=1LL*(r-m)*lazy[i];
        }
        lazy[i]=-1;
    }
    void assign(int i,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            sum[i]=1LL*(r-l+1)*c;
            maxVal[i]=lazy[i]=c;
            return;
        }
        pushDown(i,l,r);
        int m=(l+r)>>1;
        assign(2*i,l,m,u,v,c);
        assign(2*i+1,m+1,r,u,v,c);
        sum[i]=sum[2*i]+sum[2*i+1];
        maxVal[i]=max(maxVal[2*i],maxVal[2*i+1]);
    }
    int lastLess(int i,int l,int r,int x) {
        if (l>r) return (0);
        if (l==r) return (maxVal[i]<=x?r:0);
        pushDown(i,l,r);
        int m=(l+r)>>1;
        if (maxVal[2*i]<=x) return (max(m,lastLess(2*i+1,m+1,r,x)));
        return (lastLess(2*i,l,m,x));
    }
    int lastLess(int x) {
        return (lastLess(1,1,n,x));
    }
    public:
    SegmentTree(int n=0) {
        this->n=n;
        if (n>0) {
            sum.assign(4*n+7,0);
            maxVal.assign(4*n+7,0);
            lazy.assign(4*n+7,-1);
        }
    }
    void maximize(int l,int r,int x) {
        int t=lastLess(x);
        assign(1,1,n,max(1,l),min(r,t),x);
    }
    long long getSum(void) const {
        return (sum[1]);
    }
};
int a[MAX],n;
vector<int> havePos[MAX],haveDiv[MAX];
long long numGreater[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) havePos[a[i]].push_back(i);
    FOR(i,1,MAX-1) for (int j=i;j<MAX;j=j+i)
        FORE(it,havePos[j]) haveDiv[i].push_back(*it);
    FOR(i,1,MAX-1) {
        sort(ALL(haveDiv[i]));
        haveDiv[i].resize(unique(ALL(haveDiv[i]))-haveDiv[i].begin());
    }
}
void process(void) {
    SegmentTree myit(n);
    FOR(i,1,n) myit.maximize(i,i,i-1);
    FORD(i,MAX-1,1) {
        if (haveDiv[i].size()>1) {
            vector<int> &cur=haveDiv[i];
            myit.maximize(1,cur[0],cur[cur.size()-2]-1);
            myit.maximize(cur[0]+1,cur[1],cur.back()-1);
            myit.maximize(cur[1]+1,n,n);
        }
        numGreater[i]=myit.getSum()-1LL*n*(n+1)/2+n;
    }
    long long res=0;
    FOR(i,1,MAX-2) res+=1LL*i*(numGreater[i]-numGreater[i+1]);
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}