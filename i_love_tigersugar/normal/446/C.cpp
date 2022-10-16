#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int mod=(int)1e9+9;
const int mul=276601605;
const int pw1=691504013;
const int pw2=308495997;
inline void add(int &x,const int &y) {
    assert(0<=y && y<mod);
    x=(x+y)%mod;
}
class IT{
    private:
    int n,x;
    vector<int> pw,spw;
    vector<int> tree,lazy;
    void pushdown(int i,int l,int r) {
        int m=(l+r)>>1;
        add(lazy[2*i],lazy[i]);
        add(lazy[2*i+1],1LL*lazy[i]*pw[m-l+1]%mod);
        add(tree[2*i],1LL*lazy[i]*spw[m-l]%mod);
        add(tree[2*i+1],1LL*lazy[i]*pw[m-l+1]%mod*spw[r-m-1]%mod);
        lazy[i]=0;
    }
    void update(int i,int l,int r,int u,int v) {
        if (l>v) return;
        if (r<u) return;
        if (l>r) return;
        if (v<u) return;
        if (u<=l && r<=v) {
            add(lazy[i],pw[l-u+1]);
            add(tree[i],1LL*pw[l-u+1]*spw[r-l]%mod);
            return;
        }
        pushdown(i,l,r);
        int m=(l+r)>>1;
        update(2*i,l,m,u,v);
        update(2*i+1,m+1,r,u,v);
        tree[i]=(tree[2*i]+tree[2*i+1])%mod;
    }
    int getsum(int i,int l,int r,int u,int v) {
        if (l>v) return (0);
        if (r<u) return (0);
        if (l>r) return (0);
        if (v<u) return (0);
        if (u<=l && r<=v) return (tree[i]);
        pushdown(i,l,r);
        int m=(l+r)>>1;
        int L=getsum(2*i,l,m,u,v);
        int R=getsum(2*i+1,m+1,r,u,v);
        return ((L+R)%mod);
    }
    public:
    IT() {
        n=x=0;
    }
    IT(int n,int x) {
        this->n=n;
        this->x=x;
        pw.push_back(1);
        spw.push_back(1);
        FOR(i,1,n) {
            pw.push_back(1LL*x*pw.back()%mod);
            spw.push_back((pw.back()+spw.back())%mod);
        }
        tree.assign(4*n+7,0);
        lazy.assign(4*n+7,0);
    }
    void update(int l,int r) {
        update(1,1,n,l,r);
    }
    int getsum(int l,int r) {
        return (getsum(1,1,n,l,r));
    }
};
IT it1,it2;
int f[MAX],sf[MAX];
int n,q;
inline int fsum(int l,int r) {
    return ((sf[r]-sf[l-1]+mod)%mod);
}
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) {
        scanf("%d",&f[i]);
        sf[i]=(sf[i-1]+f[i])%mod;
    }
    it1=IT(n,pw1);
    it2=IT(n,pw2);
}
void update(int l,int r) {
    it1.update(l,r);
    it2.update(l,r);
}
int getsum(int l,int r) {
    //printf("GET %d %d\n",l,r);
    return ((1LL*(it1.getsum(l,r)-it2.getsum(l,r)+mod)*mul+fsum(l,r))%mod);
}
void process(void) {
    REP(zz,q) {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if (t==1) update(l,r);
        else printf("%d\n",getsum(l,r));
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}