#include<bits/stdc++.h>
#define MAX   100100
#define LOG   17
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
using namespace std;
const int INF=(int)1e9+7;
class SegmentTree {
    private:
    int n;
    vector<int> tree;
    int getMin(int i,int l,int r,int u,int v) const {
        if (l>v) return (INF);
        if (r<u) return (INF);
        if (l>r) return (INF);
        if (v<u) return (INF);
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        int L=getMin(2*i,l,m,u,v);
        int R=getMin(2*i+1,m+1,r,u,v);
        return (min(L,R));
    }
    void assign(int i,int l,int r,int x,int v) {
        if (l==r) {
            tree[i]=v;
            return;
        }
        int m=(l+r)>>1;
        if (x>m) assign(2*i+1,m+1,r,x,v);
        else assign(2*i,l,m,x,v);
        tree[i]=min(tree[2*i],tree[2*i+1]);
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,INF);
    }
    void assign(int x,int v) {
        assign(1,1,n,x,v);
    }
    int getMin(int l,int r) const {
        return (getMin(1,1,n,l,r));
    }
};
int a[MAX],f[MAX];
int maxSeq[MAX][LOG+1],minSeq[MAX][LOG+1],lg2[MAX];
int n,maxDiff,minLen;
void init(void) {
    scanf("%d%d%d",&n,&maxDiff,&minLen);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void precount(void) {
    FOR(i,1,n) maxSeq[i][0]=minSeq[i][0]=a[i];
    FOR(j,1,LOG) FOR(i,1,n-MASK(j)+1) {
        maxSeq[i][j]=max(maxSeq[i][j-1],maxSeq[i+MASK(j-1)][j-1]);
        minSeq[i][j]=min(minSeq[i][j-1],minSeq[i+MASK(j-1)][j-1]);
    }
    FOR(i,1,n) {
        while (MASK(lg2[i])<=i) lg2[i]++; lg2[i]--;
    }
}
int getMaxSeq(int l,int r) {
    int k=lg2[r-l+1];
    return (max(maxSeq[l][k],maxSeq[r-MASK(k)+1][k]));
}
int getMinSeq(int l,int r) {
    int k=lg2[r-l+1];
    return (min(minSeq[l][k],minSeq[r-MASK(k)+1][k]));
}
int maxAllow(int i) {
    int L=1;
    int R=i;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (getMaxSeq(L,i)-getMinSeq(L,i)<=maxDiff?L:R);
        int M=(L+R)>>1;
        if (getMaxSeq(M,i)-getMinSeq(M,i)<=maxDiff) R=M; else L=M+1;
    }
}
void optimize(void) {
    SegmentTree minF(n);
    FOR(i,1,n) {
        int j=maxAllow(i);
        if (i-j+1<minLen) f[i]=INF;
        else {
            if (j==1) f[i]=1;
            else {
                int l=j-1;
                int r=i-minLen;
                f[i]=minF.getMin(l,r)+1;
            }
        }
        if (f[i]>INF) f[i]=INF;
        minF.assign(i,f[i]);
    }
    if (f[n]>=INF) printf("-1"); else printf("%d",f[n]);
}
int main(void) {
    init();
    precount();
    optimize();
    return 0;
}