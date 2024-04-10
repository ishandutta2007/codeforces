#include<bits/stdc++.h>
#define MAXN   1111
#define MAXQ   100100
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
class PerSegmentTree {
    private:
    struct Node {
        Node *left,*right;
        int sum;
        Node() {
            left=right=NULL;
            sum=0;
        }
        Node(Node *p) {
            left=p->left;
            right=p->right;
            sum=p->sum;
        }
    };
    void build(Node *&root,int l,int r) {
        if (l>r) return;
        root=new Node();
        if (l==r) return;
        int m=(l+r)>>1;
        build(root->left,l,m);
        build(root->right,m+1,r);
    }
    void update(Node *&p,int l,int r,int x,int v) {
        p=new Node(p);
        if (l==r) {
            p->sum=v;
            return;
        }
        int m=(l+r)>>1;
        if (x>m) update(p->right,m+1,r,x,v);
        else update(p->left,l,m,x,v);
        p->sum=0;
        if (p->left!=NULL) p->sum+=p->left->sum;
        if (p->right!=NULL) p->sum+=p->right->sum;
    }
    int n;
    Node *root;
    public:
    PerSegmentTree(int n=0) {
        this->n=n;
        if (n>0) build(root,1,n);
    }
    void assign(int x,int v) {
        update(root,1,n,x,v);
    }
    int getSum(void) const {
        return (root->sum);
    }
    int getValue(int x) const {
        Node *p=root;
        int l=1;
        int r=n;
        while (true) {
            if (l==r) return (p->sum);
            int m=(l+r)>>1;
            if (x>m) {
                p=p->right;
                l=m+1;
            } else {
                p=p->left;
                r=m;
            }
        }
    }
};
PerSegmentTree isRev[MAXQ],numBook[MAXQ],board[MAXQ];
int id[MAXN][MAXN],m,n,q;
void process(void) {
    scanf("%d%d%d",&m,&n,&q);
    int tmp=0;
    FOR(i,1,m) FOR(j,1,n) id[i][j]=++tmp;
    isRev[0]=PerSegmentTree(m);
    numBook[0]=PerSegmentTree(m);
    board[0]=PerSegmentTree(m*n);
    FOR(i,1,q) {
        int type,x,y; scanf("%d%d",&type,&x);
        if (type<=2) scanf("%d",&y);
        if (type==4) {
            isRev[i]=isRev[x];
            numBook[i]=numBook[x];
            board[i]=board[x];
        } else {
            isRev[i]=isRev[i-1];
            numBook[i]=numBook[i-1];
            board[i]=board[i-1];
            if (type==3) {
                isRev[i].assign(x,isRev[i].getValue(x)^1);
                numBook[i].assign(x,n-numBook[i].getValue(x));
            } else {
                int curRev=isRev[i].getValue(x);
                int oldVal=board[i].getValue(id[x][y])^curRev;
                int newVal=type==1?1:0;
                board[i].assign(id[x][y],newVal^curRev);
                numBook[i].assign(x,numBook[i].getValue(x)+newVal-oldVal);
            }
        }
        printf("%d\n",numBook[i].getSum());
    }
}
int main(void) {
    process();
    return 0;
}