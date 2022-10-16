#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
class IT {
    private:
    vector<ii> tree;
    vector<ll> sum;
    int n;
    void assign(int i,int l,int r,int u,int c) {
        if (l>u) return;
        if (r<u) return;
        if (l>r) return;
        if (l==r) {
            tree[i]=ii(c,u);
            sum[i]=c;
            return;
        }
        int m=(l+r)>>1;
        assign(2*i,l,m,u,c);
        assign(2*i+1,m+1,r,u,c);
        tree[i]=max(tree[2*i],tree[2*i+1]);
        sum[i]=sum[2*i]+sum[2*i+1];
    }
    ll getsum(int i,int l,int r,int u,int v) {
        if (l>v) return (0);
        if (r<u) return (0);
        if (l>r) return (0);
        if (v<u) return (0);
        if (u<=l && r<=v) return (sum[i]);
        int m=(l+r)>>1;
        ll L=getsum(2*i,l,m,u,v);
        ll R=getsum(2*i+1,m+1,r,u,v);
        return (L+R);
    }
    ii findmax(int i,int l,int r,int u,int v) {
        if (l>v) return (ii(-1,-1));
        if (r<u) return (ii(-1,-1));
        if (l>r) return (ii(-1,-1));
        if (v<u) return (ii(-1,-1));
        if (u<=l && r<=v) return (tree[i]);
        int m=(l+r)>>1;
        ii L=findmax(2*i,l,m,u,v);
        ii R=findmax(2*i+1,m+1,r,u,v);
        return (max(L,R));
    }
    public:
    IT() {
        n=0;
    }
    IT(int n) {
        this->n=n;
        tree=vector<ii>(4*n+7);
        sum=vector<ll>(4*n+7);
    }
    void assign(int i,int v) {
        assign(1,1,n,i,v);
    }
    ll getsum(int l,int r) {
        return (getsum(1,1,n,l,r));
    }
    void modul(int l,int r,int x) {
        while (true) {
            ii t=findmax(1,1,n,l,r);
            if (t.fi<x) return;
            assign(t.se,t.fi%x);
        }
    }
};
IT myit;
void process(void) {
    int n,q;
    scanf("%d%d",&n,&q);
    myit=IT(n);
    FOR(i,1,n) {
        int v;
        scanf("%d",&v);
        myit.assign(i,v);
    }
    REP(zz,q) {
        int t,u,v,w;
        scanf("%d%d%d",&t,&u,&v);
        if (t==2) scanf("%d",&w);
        if (t==3) myit.assign(u,v);
        if (t==2) myit.modul(u,v,w);
        if (t==1) cout<<myit.getsum(u,v)<<"\n";
    }
}
int main(void) {
    process();
    return 0;
}