#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
void maximize(ll &x,const ll &y) {
    if (x<y) x=y;
}
class TREE {
    public:
    vector<vector<int> > g;
    vector<int> h,p,sz;
    vector<ll> s,mx,my,best;
    int n;
    ll sdis,mdis;
    TREE() {
        n=0;sdis=0LL;mdis=0LL;
    }
    TREE(int n) {
        this->n=n;
        sdis=0LL;
        mdis=0LL;
        g.assign(n+7,vector<int>());
        p=vector<int>(n+7,0);
        h=vector<int>(n+7,0);
        sz=vector<int>(n+7,0);
        s=vector<ll>(n+7,0LL);
        mx=vector<ll>(n+7,0LL);
        my=vector<ll>(n+7,0LL);
        best=vector<ll>(n+7,0LL);
    }
    void update(const vector<ll> &v,int &a,int &b,int c) {
        if (a<0 || v[c]>v[a]) {			
            b=a;
            a=c;
            return;
        }
		//cerr << "123" << endl;
        if (b<0 || v[c]>v[b]) b=c;
    }
    void addedge(int u,int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs1(int u) {
        s[1]+=h[u];
        sz[u]=1;
        FORE(it,g[u]) if (*it!=p[u]) {
            int v=*it;
            p[v]=u;
            h[v]=h[u]+1;
            dfs1(v);
            sz[u]+=sz[v];
            sdis+=1LL*sz[v]*(n-sz[v]);
        }
    }
    void dfs2(int u) {
        FORE(it,g[u]) if (*it!=p[u]) {
            int v=*it;
            s[v]=s[u]+n-2*sz[v];
            dfs2(v);
        }
    }
    void dfsq(int u,int x,int y) {		
        mx[u]=s[u]*x;
        my[u]=s[u]*y;
        int iax=-1;
        int iay=-1;
        int ibx=-1;
        int iby=-1;
        FORE(it,g[u]) if (*it!=p[u]) {
            int v=*it;			
            dfsq(v,x,y);
            maximize(mx[u],mx[v]+1LL*x*y);
            maximize(my[u],my[v]+1LL*y*x);			
            update(mx,iax,ibx,v);			
            update(my,iay,iby,v);			
        }		
        if (ibx<0 || iby<0) {
            best[u]=-1LL;
            return;
        }
        if (iax!=iay) {
            best[u]=mx[iax]+my[iay]+2LL*x*y;
            return;
        }		
        best[u]=max(mx[iax]+my[iby],mx[ibx]+my[iay])+2LL*x*y;
    }
    void process(void) {
        REP(i,n-1) {
            int u,v;
            scanf("%d",&u);
            scanf("%d",&v);
            addedge(u,v);
        }
        dfs1(1);
        dfs2(1);
        FOR(i,1,n) mdis=max(mdis,s[i]);                
    }
    ll maxdistance(int x,int y) {		
        dfsq(1,x,y);
        ll ret=-1LL;
        FOR(i,1,n) {
            maximize(ret,best[i]);
            maximize(ret,s[i]*x+my[i]);
            maximize(ret,mx[i]+s[i]*y);
        }		
        return (ret);
    }
};
TREE tree[3];
void process(void) {
    REP(i,3) {
        int n;
        scanf("%d",&n);
        tree[i]=TREE(n);
    }
    REP(i,3) tree[i].process();
    ll res=-1LL;
    ll sum=0LL;
    REP(i,3) sum+=tree[i].sdis;
    REP(t,3) FOR(j,1,2) {
        int x=(t+j)%3;
        int y=(t+j*2)%3;
        //cerr << t << " " << x << " " << y << endl;
        ll tmp=tree[x].mdis*(tree[t].n+tree[y].n)+tree[y].mdis*(tree[t].n+tree[x].n)+1LL*tree[x].n*(tree[t].n+tree[y].n)+1LL*tree[y].n*(tree[x].n+tree[t].n);
        maximize(res,tmp+tree[t].maxdistance(tree[x].n,tree[y].n));
    }
    cout << res+sum;
}
int main(void) {
	//freopen("tmp.inp","r",stdin);
    process();
    return 0;
}