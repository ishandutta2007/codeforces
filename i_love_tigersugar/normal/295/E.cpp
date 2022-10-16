#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX   300300
using namespace std;
typedef long long ll;
struct num {
    ll val;
    int cmp;
    num(){}
    num(const ll &v,const int &c) {
        val=v;cmp=c;
    }
};
struct query {
    int type;
    num fst,scd;
    query(){}
    query(const int &t,const ll &x1,const ll &x2) {
        type=t;
        fst.val=x1;
        scd.val=x2;
    }
};
struct nod {
    ll sdis;
    ll spos;
    int npnt;
    nod(){
        sdis=0;spos=0;npnt=0;
    }
    nod(const ll &sd,const ll &sp,const int &np) {
        sdis=sd;spos=sp;npnt=np;
    }
    nod operator + (const nod &x) const {
        nod res;
        res.npnt=npnt+x.npnt;
        res.spos=spos+x.spos;
        res.sdis=sdis+x.sdis+x.spos*npnt-spos*x.npnt;
        return (res);
    }
};
vector<ll> vnum;
query lst[MAX];
nod tree[4*MAX];
int n,q;
num a[MAX];
ll b[MAX];
ll va[MAX];
void init(void) {
    vnum.clear();
    int i,j,t;
    ll f,l;
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1) {
        scanf("%I64d",&b[i]);
        a[i].val=b[i];
        vnum.push_back(b[i]);
    }
    scanf("%d",&q);
    for (i=1;i<=q;i=i+1) {
        scanf("%d",&t);
        if (t==1) {
            scanf("%d",&j);
            scanf("%I64d",&f);
            lst[i]=query(1,b[j],b[j]+f);
            b[j]=b[j]+f;
            vnum.push_back(b[j]);
        }
        if (t==2) {
            scanf("%I64d",&f);
            scanf("%I64d",&l);
            lst[i]=query(2,f,l);
            vnum.push_back(f);
            vnum.push_back(l);
        }
    }
}
void compress(void) {
    int i;
    sort(vnum.begin(),vnum.end());
    for (i=1;i<=n;i=i+1) {
        a[i].cmp=lower_bound(vnum.begin(),vnum.end(),a[i].val)-vnum.begin()+1;
        va[a[i].cmp]=a[i].val;
    }
    for (i=1;i<=q;i=i+1) {
        lst[i].fst.cmp=lower_bound(vnum.begin(),vnum.end(),lst[i].fst.val)-vnum.begin()+1;
        lst[i].scd.cmp=lower_bound(vnum.begin(),vnum.end(),lst[i].scd.val)-vnum.begin()+1;
        va[lst[i].fst.cmp]=lst[i].fst.val;
        va[lst[i].scd.cmp]=lst[i].scd.val;
    }
}
void update(int i,int l,int r,int u,int val) {
    if (l>u) return;
    if (r<u) return;
    if (l>r) return;
    if (l==r) {
        tree[i].npnt+=val;
        tree[i].spos+=val*va[u];
        return;
    }
    int m=(l+r)/2;
    update(2*i,l,m,u,val);
    update(2*i+1,m+1,r,u,val);
    tree[i]=tree[2*i]+tree[2*i+1];
}
nod getinf(int i,int l,int r,int u,int v) {
    if (l>v) return (nod());
    if (r<u) return (nod());
    if (l>r) return (nod());
    if (u<=l && r<=v) return (tree[i]);
    int m=(l+r)/2;
    nod t1=getinf(2*i,l,m,u,v);
    nod t2=getinf(2*i+1,m+1,r,u,v);
    return (t1+t2);
}
void answer(void) {
    int i;
    for (i=0;i<4*MAX;i=i+1) tree[i]=nod();
    for (i=1;i<=n;i=i+1) update(1,1,MAX-300,a[i].cmp,1);
    for (i=1;i<=q;i=i+1) {
        if (lst[i].type==1) {
            update(1,1,MAX-300,lst[i].fst.cmp,-1);
            update(1,1,MAX-300,lst[i].scd.cmp,1);
        }
        if (lst[i].type==2) printf("%I64d\n",getinf(1,1,MAX-300,lst[i].fst.cmp,lst[i].scd.cmp).sdis);
    }
}
int main(void) {
    //freopen("tmp.inp","r",stdin);
    init();
    compress();
    answer();
    return 0;
}