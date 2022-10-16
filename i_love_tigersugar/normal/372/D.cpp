#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
vector<int> g[MAX];
int sta[MAX],fin[MAX],p[MAX][18],h[MAX];
int n,q,cnt;
class cmp {
    public:
    bool operator () (const int &a,const int &b) const {
        return (sta[a]<sta[b]);
    }
};
set<int,cmp> s;
typedef set<int,cmp>::iterator sit;
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void loadtree(void) {
    scanf("%d",&n);
    scanf("%d",&q);
    q=q-1;
    REP(i,n-1) {
        int u,v;
        scanf("%d",&u);
        scanf("%d",&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[0]=-1;
}
void visit(int u) {
    cnt++;
    sta[u]=cnt;
    FORE(it,g[u]) if (*it!=p[u][0]) {
        int v=*it;
        p[v][0]=u;
        h[v]=h[u]+1;
        visit(v);
    }
    fin[u]=cnt;
}
void setup_LCA(void) {
    visit(1);
    FOR(j,1,17) FOR(i,1,n) p[i][j]=p[p[i][j-1]][j-1];
}
int LCA(int u,int v) {
    if (h[u]<h[v]) return (LCA(v,u));
    FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (u==v) return (u);
    FORD(i,17,0) if (p[u][i]!=p[v][i]) {
        u=p[u][i];
        v=p[v][i];
    }
    return (p[u][0]);
}
int dis(int u,int v) {
    return (h[u]+h[v]-2*h[LCA(u,v)]);
}
bool isparent(int u,int v) {
    return (sta[u]<=sta[v] && sta[v]<=fin[u]);
}
bool isfirst(sit x) {
    return (x==s.begin());
}
bool islast(sit x) {
    x++;
    return (x==s.end());
}
void addnode(int x,int &root,int &cur) {
    //printf("add node %d: before %d %d\n",x,root,cur);
    assert(!s.empty());
    sit pos=s.insert(x).fi;
    if (isfirst(pos)) {
        int nroot=LCA(x,root);
        pos++;
        cur-=dis(root,*pos);
        cur+=dis(nroot,x);
        cur+=dis(LCA(x,*pos),*pos);
        root=nroot;
        //printf("after %d %d\n",root,cur);
        return;
    }
    if (islast(pos)) {
        int nroot=LCA(x,root);
        pos--;
        cur-=dis(root,*s.begin());
        cur+=dis(nroot,*s.begin());
        cur+=dis(LCA(*pos,x),x);
        root=nroot;
        //printf("after %d %d\n",root,cur);
        return;
    }
    pos--;
    int u=*pos;
    pos++;pos++;
    int v=*pos;
    cur-=dis(LCA(u,v),v);
    cur+=dis(LCA(u,x),x);
    cur+=dis(LCA(x,v),v);
    //printf("after %d %d\n",root,cur);
}
void remnode(int x,int &root,int &cur) {
    //printf("rem node %d: before %d %d\n",x,root,cur);
    sit pos=s.find(x);
    assert(pos!=s.end());
    if (isfirst(pos)) {
        pos++;
        sit lst=s.end();lst--;
        int nroot=LCA(*pos,*lst);
        cur-=dis(root,x);
        cur-=dis(LCA(x,*pos),*pos);
        cur+=dis(nroot,*pos);
        root=nroot;
        s.erase(x);
        //printf("after %d %d\n",root,cur);
        return;
    }
    if (islast(pos)) {
        pos--;
        int nroot=LCA(*s.begin(),*pos);
        cur-=dis(root,*s.begin());
        cur+=dis(nroot,*s.begin());
        cur-=dis(LCA(*pos,x),x);
        root=nroot;
        s.erase(x);
        //printf("after %d %d\n",root,cur);
        return;
    }
    pos--;
    int u=*pos;
    pos++;pos++;
    int v=*pos;
    cur-=dis(LCA(u,x),x);
    cur-=dis(LCA(x,v),v);
    cur+=dis(LCA(u,v),v);
    s.erase(x);
    //printf("after %d %d\n",root,cur);
}
void process(void) {
    s.insert(1);
    int cur=0;
    int root=1;
    int j=1;
    int res=1;
    FOR(i,2,n) {
        addnode(i,root,cur);
        while (j<i && cur>q) {
            remnode(j,root,cur);
            j++;
        }
        maximize(res,i-j+1);
    }
    printf("%d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    loadtree();
    setup_LCA();
    process();
    return 0;
}