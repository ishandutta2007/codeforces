#include<bits/stdc++.h>
#define MAX   100100
#define LOG   33
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
class SegmentTree {
    private:
    struct Info {
        int maxSeq,left,right,len;
        Info() {
            maxSeq=left=right=len=0;
        }
        Info(int x) {
            maxSeq=left=right=x;len=1;
        }
        Info operator + (const Info &x) const {
            Info res;
            res.len=len+x.len;
            res.maxSeq=max(max(maxSeq,x.maxSeq),right+x.left);
            res.left=left==len?left+x.left:left;
            res.right=x.right==x.len?x.right+right:x.right;
            return (res);
        }
    };
    int n;
    vector<Info> tree;
    void assign(int i,int l,int r,int x) {
        if (l==r) {
            tree[i]=Info(1);
            return;
        }
        int m=(l+r)>>1;
        if (x>m) assign(2*i+1,m+1,r,x);
        else assign(2*i,l,m,x);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    Info getInfo(int i,int l,int r,int u,int v) const {
        if (l>v) return (Info());
        if (r<u) return (Info());
        if (l>r) return (Info());
        if (v<u) return (Info());
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        Info L=getInfo(2*i,l,m,u,v);
        Info R=getInfo(2*i+1,m+1,r,u,v);
        return (L+R);
    }
    void build(int i,int l,int r) {
        if (l>r) return;
        if (l==r) tree[i]=Info(0);
        else {
            int m=(l+r)>>1;
            build(2*i,l,m);
            build(2*i+1,m+1,r);
            tree[i]=tree[2*i]+tree[2*i+1];
        }
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        tree.assign(4*n+7,Info());
        build(1,1,n);
    }
    void assign(int x) {
        assign(1,1,n,x);
    }
    int getMaxSeq(int l,int r) {
        return (getInfo(1,1,n,l,r).maxSeq);
    }
};
struct Triple {
    int fi,se,th;
    Triple() {
        fi=se=th=0;
    }
    Triple(int x,int y,int z) {
        fi=x;se=y;th=z;
    }
    bool operator < (const Triple &x) const {
        if (fi!=x.fi) return (fi<x.fi);
        if (se!=x.se) return (se<x.se);
        if (th!=x.th) return (th<x.th);
    }
};
int a[MAX],order[MAX],L[MAX],R[MAX];
int n,q;
Triple query[MAX];
bool Comp(int x,int y) {
    return (a[x]>a[y]);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&q);
    REP(i,q) scanf("%d%d%d",&query[i].se,&query[i].th,&query[i].fi);
    FOR(i,1,n) order[i]=i;
    sort(order+1,order+n+1,Comp);
}
void answerQuery(vector<pair<Triple,int> > &query,vector<int> &answer) {
    sort(query.begin(),query.end(),greater<pair<Triple,int> >());
    answer.clear();
    SegmentTree segmentTree(n);
    int id=1;
    FORE(it,query) {
        while (id<=n && a[order[id]]>=it->fi.fi) {
            segmentTree.assign(order[id]);
            id++;
        }
        answer.push_back(segmentTree.getMaxSeq(it->fi.se,it->fi.th));
    }
}
void process(void) {
    REP(i,q) {
        L[i]=0;
        R[i]=INF;
    }
    REP(zz,LOG) {
        vector<pair<Triple,int> > toAsk;
        vector<int> answer;
        REP(i,q) {
            int midVal=R[i]-L[i]==1?R[i]:(L[i]+R[i])>>1;
            toAsk.push_back(make_pair(Triple(midVal,query[i].se,query[i].th),i));
        }
        answerQuery(toAsk,answer);
        REP(i,q) {
            int id=toAsk[i].se;
            if (L[id]==R[id]) continue;
            bool ok=answer[i]>=query[id].fi;
            if (R-L==1) {
                if (ok) L[id]++; else R[id]--;
            } else {
                if (ok) L[id]=toAsk[i].fi.fi; else R[id]=toAsk[i].fi.fi-1;
            }
        }
    }
    REP(i,q) {
        assert(L[i]==R[i]);
        printf("%d\n",L[i]);
    }
}
int main(void) {
    init();
    process();
    return 0;
}