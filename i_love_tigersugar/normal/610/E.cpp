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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int n,q,m;
class SegmentTree {
    public:
    struct Node {
        int cnt[11][11];
        int first,last,same;
        Node() {
            memset(cnt,0,sizeof cnt);
            first=last=same=-2;
        }
        Node(int x,int len) {
            memset(cnt,0,sizeof cnt);
            cnt[x][x]=len-1;
            first=last=same=x;
            debug();
        }
        Node operator + (const Node &x) const {
            if (same==-2) return (x);
            if (x.same==-2) return (*this);
            Node res;
            REP(i,m) REP(j,m) res.cnt[i][j]=cnt[i][j]+x.cnt[i][j];
            assert(0<=last && last<m && 0<=x.first && x.first<m);
            res.cnt[last][x.first]++;
            assert(res.cnt[last][x.first]>0);
            res.first=first;
            res.last=x.last;
            res.same=-1;
            return (res);
        }
        void debug(void) const {
            REP(i,m) REP(j,m) assert(cnt[i][j]>=0);
            //REP(i,m) REP(j,m) if (cnt[i][j]>0)
          //      printf("cnt of %c %c is %d\n",i+'a',j+'a',cnt[i][j]);
        }
    };
    void pushdown(int i,int l,int r) {
        if (tree[i].same<0) return;
        int m=(l+r)>>1;
        tree[2*i]=Node(tree[i].same,m-l+1);
        tree[2*i+1]=Node(tree[i].same,r-m);
        tree[i].same=-1;
        tree[i].debug();
        tree[2*i].debug();
        tree[2*i+1].debug();
    }
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[i]=Node(c,r-l+1);
            return;
        }
        pushdown(i,l,r);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    void build(int i,int l,int r,char s[]) {
        if (l==r) {
            tree[i]=Node(s[l]-'a',1);
            return;
        }
        int m=(l+r)>>1;
        build(2*i,l,m,s);
        build(2*i+1,m+1,r,s);
        tree[i]=tree[2*i]+tree[2*i+1];
        /*printf("node %d (%d,%d)\n",i,l,r);
        tree[i].debug();*/
    }
    void debug(int i,int l,int r) const {
        if (l==r) return (tree[i].debug());
        int m=(l+r)>>1;
        debug(2*i,l,m);
        debug(2*i+1,m+1,r);
        //printf("NODE %d (%d,%d)\n",i,l,r);
        tree[i].debug();
    }
    vector<Node> tree;
    int n;
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(char s[],int n) {
        this->n=n;
        tree.assign(4*n+7,Node());
        build(1,1,n,s);
    }
    void update(int l,int r,int c) {
        update(1,1,n,l,r,c);
    }
    int get(char s[]) const {
        int res=0;
        REP(i,m) REP(j,i+1) res+=tree[1].cnt[s[i]-'a'][s[j]-'a'];
        return (res);
    }
    void debug(void) const {
        debug(1,1,n);
    }
};
char s[MAX];
void process(void) {
    scanf("%d%d%d",&n,&q,&m);
    scanf("%s",s+1);
    SegmentTree myit(s,n);
    //myit.debug();
    REP(love,q) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            int l,r;
            char tmp[3];
            scanf("%d%d",&l,&r);
            scanf("%s",tmp);
            myit.update(l,r,tmp[0]-'a');
        } else {
            char tmp[13];
            scanf("%s",tmp);
            printf("%d\n",myit.get(tmp)+1);
        }
        //myit.debug();
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    process();
    return 0;
}