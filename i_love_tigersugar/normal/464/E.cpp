#include<bits/stdc++.h>
#define MAX   100100
#define nmod   3
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
const int mod[]={(int)1e9+7,(int)1e9+9,(int)1e9+21,(int)1e9+33};
int pw[nmod][MAX+7];
struct hash {
    int len,code[nmod];
    hash() {
        len=0;
        memset(code,0,sizeof code);
    }
    hash(int x) {
        len=1;
        REP(i,nmod) code[i]=x;
    }
    hash operator + (const hash &x) const {
        hash res;
        res.len=len+x.len;
        REP(i,nmod) res.code[i]=(1LL*x.code[i]*pw[i][len]+code[i])%mod[i];
        return (res);
    }
    bool operator == (const hash &x) const {
        if (len!=x.len) return (false);
        REP(i,nmod) if (code[i]!=x.code[i]) return (false);
        return (true);
    }
};
class BinaryNumber {
    private:
    struct node {
        hash val;
        node *ch[2];
        node() {
            REP(i,2) ch[i]=NULL;
        }
        node(int x) {
            val=hash(x);
            REP(i,2) ch[i]=NULL;
        }
        node(node *p) {
            val=p->val;
            REP(i,2) ch[i]=p->ch[i];
        }
    };
    void build(node *&t,int l,int r,int x) {
        if (l>r) return;
        if (l==r) {
            t=new node(x);
            return;
        }
        t=new node();
        int m=(l+r)>>1;
        build(t->ch[0],l,m,x);
        build(t->ch[1],m+1,r,x);
        t->val=t->ch[0]->val+t->ch[1]->val;
    }
    int prevzero(node *p,int l,int r,int x,node *base) const {
        if (r<x) return (x-1);
        if (p->val==base->val) return (x-1);
        if (l==r) return (r);
        int m=(l+r)>>1;
        int tmp=prevzero(p->ch[0],l,m,x,base->ch[0]);
        return (tmp>=x?tmp:prevzero(p->ch[1],m+1,r,x,base->ch[1]));
    }
    void assign(node *q,node *&p,int l,int r,int u,int v,int dir,node *base) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            p=base;
            if (q==NULL) root=p; else q->ch[dir]=p;
            return;
        }
        p=new node(p);
        if (q==NULL) root=p; else q->ch[dir]=p;
        int m=(l+r)>>1;
        assign(p,p->ch[0],l,m,u,v,0,base->ch[0]);
        assign(p,p->ch[1],m+1,r,u,v,1,base->ch[1]);
        p->val=p->ch[0]->val+p->ch[1]->val;
    }
    node *root;
    int n;
    public:
    BinaryNumber() {
        root=NULL;
        n=0;
    }
    BinaryNumber(int n,int x) {
        this->n=n;
        build(root,1,n,x);
    }
    int prevzero(int x,const BinaryNumber &base) const {
        return (prevzero(root,1,n,x,base.root));
    }
    void assign(int l,int r,const BinaryNumber &base) {
        assign(NULL,root,1,n,l,r,0,base.root);
    }
    bool operator == (const BinaryNumber &x) const {
        return (root->val==x.root->val);
    }
    bool operator < (const BinaryNumber &x) const {
        if (*this==x) return (false);
        node *p=root;
        node *px=x.root;
        int l=1;
        int r=n;
        while (true) {
            if (l==r) return (p->val.code[0]<px->val.code[0]);
            int m=(l+r)>>1;
            if (p->ch[1]->val==px->ch[1]->val) {
                p=p->ch[0];
                px=px->ch[0];
                r=m;
            }
            else {
                p=p->ch[1];
                px=px->ch[1];
                l=m+1;
            }
        }
    }
    bool operator > (const BinaryNumber &x) const {
        return (x<*this);
    }
    int gethash(void) const {
        return (root->val.code[0]);
    }
};
BinaryNumber base[2];
BinaryNumber operator + (const BinaryNumber &b,int x) {
    int id=b.prevzero(x,base[1]);
    BinaryNumber res=b;
    res.assign(id,id,base[1]);
    res.assign(x,id-1,base[0]);
    return (res);
}
typedef pair<BinaryNumber,int> bi;
vector<ii> g[MAX];
BinaryNumber d[MAX];
int n,m,s,e;
int t[MAX];
inline void add(int &x,const int &y,int mod) {
    x+=y;
    if (x>=mod) x-=mod;
}
void precount(void) {
    REP(j,nmod) {
        pw[j][0]=1;
        FOR(i,1,MAX) REP(zz,2) add(pw[j][i],pw[j][i-1],mod[j]);
    }
    REP(i,2) base[i]=BinaryNumber(MAX,i);
}
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(zz,m) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        g[u].push_back(ii(v,c+1));
        g[v].push_back(ii(u,c+1));
    }
    scanf("%d%d",&s,&e);
}
void dijkstra(void) {
    priority_queue<bi,vector<bi>,greater<bi> > q;
    FOR(i,1,n) d[i]=base[1];
    d[s]=base[0];
    q.push(bi(d[s],s));
    while (!q.empty()) {
        BinaryNumber w=q.top().fi;
        int u=q.top().se;
        q.pop();
        if (w>d[u]) continue;
        FORE(it,g[u]) if (w+it->se<d[it->fi]) {
            int v=it->fi;
            d[v]=w+it->se;
            t[v]=u;
            q.push(bi(d[v],v));
        }
    }
}
void trace(void) {
    if (d[e]==base[1]) {
        printf("-1");
        return;
    }
    printf("%d\n",d[e].gethash());
    vector<int> way;
    int cur=e;
    while (cur!=s) {
        way.push_back(cur);
        cur=t[cur];
    }
    way.push_back(s);
    reverse(way.begin(),way.end());
    printf("%d\n",way.size());
    FORE(it,way) printf("%d ",*it);
}
int main(void) {
    precount();
    loadgraph();
    dijkstra();
    trace();
    return 0;
}