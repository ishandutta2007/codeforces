#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
class SegmentTree {
    private:
    int n;
    vector<int> tree,lazy;
    void pushdown(int i) {
        FOR(j,2*i,2*i+1) {
            tree[j]+=lazy[i];
            lazy[j]+=lazy[i];
        }
        lazy[i]=0;
    }
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            tree[i]+=c;
            lazy[i]+=c;
            return;
        }
        pushdown(i);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }
    int getMax(int i,int l,int r,int u,int v) {
        if (l>v) return (-INF);
        if (r<u) return (-INF);
        if (l>r) return (-INF);
        if (v<u) return (-INF);
        if (u<=l && r<=v) return (tree[i]);
        pushdown(i);
        int m=(l+r)>>1;
        int L=getMax(2*i,l,m,u,v);
        int R=getMax(2*i+1,m+1,r,u,v);
        return (max(L,R));
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,0);
        lazy.assign(4*n+7,0);
    }
    void update(int l,int r,int c) {
        update(1,1,n,l,r,c);
    }
    int getMax(int l,int r) {
        return (getMax(1,1,n,l,r));
    }
    void maximize(int pos,int val) {
        int tmp=getMax(pos,pos);
        if (tmp>=val) return;
        update(pos,pos,val-tmp);
    }
};
int a[MAX],n,maxLen;
int maxLeft[MAX],maxRight[MAX],lastRight[MAX];
vector<int> haveLeft[MAX],haveRight[MAX];
SegmentTree allSeq;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void countLength(void) {
    SegmentTree getLeft(MAX);
    FOR(i,1,n) {
        maxLeft[i]=getLeft.getMax(1,a[i]-1)+1;
        if (maxLeft[i]<1) maxLeft[i]=1;
        getLeft.maximize(a[i],maxLeft[i]);
    }
    SegmentTree getRight(MAX);
    FORD(i,n,1) {
        maxRight[i]=getRight.getMax(a[i]+1,MAX)+1;
        if (maxRight[i]<1) maxRight[i]=1;
        getRight.maximize(a[i],maxRight[i]);
    }
    FOR(i,1,n) maxLen=max(maxLen,maxLeft[i]);
}
void countRemove(void) {
    FORD(i,n,1) haveLeft[maxLeft[i]].push_back(i);
    FORD(i,n,1) haveRight[maxRight[i]].push_back(i);
    SegmentTree segmentTree(MAX);
    FOR(i,1,n) if (!haveLeft[i].empty()) {
        vector<int> &curLeft=haveLeft[i];
        vector<int> &curRight=haveRight[maxLen-i];
        int id=0;
        FORE(it,curLeft) {
            while (id<curRight.size() && curRight[id]>*it) {
                int tmp=curRight[id];
                segmentTree.maximize(a[tmp],tmp);
                id++;
            }
            lastRight[*it]=segmentTree.getMax(a[*it]+1,MAX);
        }
        FORE(it,curRight) {
            int val=segmentTree.getMax(a[*it],a[*it]);
            if (val==0) continue;
            segmentTree.update(a[*it],a[*it],-val);
        }
    }
    allSeq=SegmentTree(n);
    FOR(i,1,n) if (lastRight[i]>i) allSeq.update(i+1,lastRight[i]-1,1);
}
bool inAllSeq(int x) {
    if (!haveLeft[maxLen].empty() && haveLeft[maxLen].back()<x) return (false);
    if (!haveRight[maxLen].empty() && haveRight[maxLen][0]>x) return (false);
    return (allSeq.getMax(x,x)==0);
}
void process(void) {
    FOR(i,1,n) {
        if (maxLeft[i]+maxRight[i]-1<maxLen) printf("1");
        else if (!inAllSeq(i)) printf("2");
        else printf("3");
    }
}
int main(void) {
    init();
    countLength();
    countRemove();
    process();
    return 0;
}