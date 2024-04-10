#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
const char yes[]="YES";
const char no[]="NO";
class SegmentTree {
private:
    vector<int> tree;
    int n;
    void assign(int i,int l,int r,int x,int v) {
        if (l==r) {
            tree[i]=v;
            return;
        }
        int m=(l+r)>>1;
        if (x>m) assign(2*i+1,m+1,r,x,v);
        else assign(2*i,l,m,x,v);
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }
    int getMax(int i,int l,int r,int u,int v) const {
        if (l>v || r<u || l>r || v<u) return (0);
        if (u<=l && r<=v) return (tree[i]);
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
    }
    void assign(int x,int v) {
        assign(1,1,n,x,v);
    }
    int getMax(int l,int r) const {
        return (getMax(1,1,n,l,r));
    }
};
struct Query {
    int top,bot,left,right,id;
    Query() {
        top=bot=left=right=id=0;
    }
    void input(int id) {
        this->id=id;
        scanf("%d%d%d%d",&top,&left,&bot,&right);
    }
};
bool CompLeft(const Query &a,const Query &b) {
    return (a.left<b.left);
}
bool CompTop(const Query &a,const Query &b) {
    return (a.top<b.top);
}
int m,n,p,q;
Query query[MAX];
bool answer[MAX];
pair<int,int> rook[MAX];
priority_queue<int,vector<int>,greater<int> > atRow[MAX],atCol[MAX];
void init(void) {
    scanf("%d%d%d%d",&m,&n,&p,&q);
    FOR(i,1,p) scanf("%d%d",&rook[i].fi,&rook[i].se);
    FOR(i,1,q) query[i].input(i);
}
bool CompRow(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.fi<b.fi);
}
bool CompCol(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.se<b.se);
}
void checkRow(void) {
    sort(rook+1,rook+p+1,CompCol);
    sort(query+1,query+q+1,CompLeft);
    FOR(i,1,p) atRow[rook[i].fi].push(rook[i].se);
    SegmentTree myit(m);
    FOR(i,1,m) myit.assign(i,atRow[i].empty()?MAX:atRow[i].top());
    int j=1;
    FOR(i,1,q) {
        while (j<=p && rook[j].se<query[i].left) {
            int x=rook[j].fi;
            atRow[x].pop();
            myit.assign(x,atRow[x].empty()?MAX:atRow[x].top());
            j++;
        }
        if (myit.getMax(query[i].top,query[i].bot)<=query[i].right) answer[query[i].id]=true;
    }
}
void checkCol(void) {
    sort(rook+1,rook+p+1,CompRow);
    sort(query+1,query+q+1,CompTop);
    FOR(i,1,p) atCol[rook[i].se].push(rook[i].fi);
    SegmentTree myit(n);
    FOR(i,1,n) myit.assign(i,atCol[i].empty()?MAX:atCol[i].top());
    int j=1;
    FOR(i,1,q) {
        while (j<=p && rook[j].fi<query[i].top) {
            int y=rook[j].se;
            atCol[y].pop();
            myit.assign(y,atCol[y].empty()?MAX:atCol[y].top());
            j++;
        }
        if (myit.getMax(query[i].left,query[i].right)<=query[i].bot) answer[query[i].id]=true;
    }
}
void process(void) {
    FOR(i,1,q) printf("%s\n",answer[i]?yes:no);
}
int main(void) {
    init();
    checkRow();
    checkCol();
    process();
    return 0;
}