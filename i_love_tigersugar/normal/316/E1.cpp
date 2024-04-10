#include<cassert>
#include<cstdio>
#include<queue>
#define MAX   200200
#define x   first
#define y   second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll mod=(ll)1e9;
ll a[MAX];
ll f[MAX];
ll s[MAX];
ll tre0[MAX<<2];
ll tre1[MAX<<2];
ll lazy[MAX<<2];
int n,q;
const ii zero=ii(0LL,0LL);
int max(const int &x,const int &y) {
    if (x>y) return (x); else return (y);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&q);
    int i;  
    f[0]=1LL;
    f[1]=1LL;
    s[0]=1LL;
    s[1]=2LL;
    for (i=2;i<=n;i=i+1) {
        f[i]=(f[i-1]+f[i-2])%mod;
        s[i]=(s[i-1]+f[i])%mod;
    }
}
ll sumfib(const int &l,const int &r) {
    if (l==0) return (s[r]);
    return ((s[r]-s[l-1]+mod)%mod);
}
ll value(const ll &s0,const ll &s1,const int &x) {
    if (x==0) return (s0);
    if (x==1) return (s1);
    return (((s0*f[x-2])%mod+(s1*f[x-1])%mod)%mod);
}
void assign(const int &x,const ll &val) {
    //printf("Assigning %d with %I64d\n",x,val);
    int i,l,m,r;
    i=1;
    l=1;
    r=n;
    ll add=0LL;
    while (true) {
        if (l==r) break;
        add=(add+lazy[i])%mod;      
        m=(l+r)/2;
        if (x>m) {
            i=2*i+1;
            l=m+1;
        }
        else {
            i=2*i;
            r=m;
        }
    }
    ll del=((val-add-a[x])%mod+mod)%mod;    
    assert(0<=del && del<mod);
    a[x]=(val-add+mod)%mod;
    i=1;
    l=1;
    r=n;
    while (true) {
        tre0[i]=(tre0[i]+(del*f[x-l])%mod)%mod;
        tre1[i]=(tre1[i]+(del*f[x-l+1])%mod)%mod;
        if (l==r) break;
        m=(l+r)/2;
        if (x>m) {
            i=2*i+1;
            l=m+1;
        }
        else {
            i=2*i;
            r=m;
        }
    }
}
void update(int i,int l,int r,int u,int v,const ll &val) {
    if (l>v) return;
    if (r<u) return;
    if (l>r) return;
    if (v<u) return;
    if (u<=l && r<=v) {
        lazy[i]=(lazy[i]+val)%mod;
        tre0[i]=(tre0[i]+(val*sumfib(0,r-l))%mod)%mod;
        tre1[i]=(tre1[i]+(val*sumfib(1,r-l+1))%mod)%mod;
        return;
    }
    int m=(l+r)/2;
    tre0[2*i]=(tre0[2*i]+(lazy[i]*sumfib(0,m-l))%mod)%mod;
    tre1[2*i]=(tre0[2*i]+(lazy[i]*sumfib(1,m-l+1))%mod)%mod;
    lazy[2*i]=(lazy[2*i]+lazy[i])%mod;
    tre0[2*i+1]=(tre0[2*i+1]+(lazy[i]*sumfib(0,r-m-1))%mod)%mod;
    tre1[2*i+1]=(tre1[2*i+1]+(lazy[i]*sumfib(1,r-m))%mod)%mod;
    lazy[2*i+1]=(lazy[2*i+1]+lazy[i])%mod;
    lazy[i]=0LL;
    update(2*i,l,m,u,v,val);
    update(2*i+1,m+1,r,u,v,val);
    tre0[i]=(tre0[2*i]+value(tre0[2*i+1],tre1[2*i+1],m-l+1))%mod;
    tre1[i]=(tre1[2*i]+value(tre0[2*i+1],tre1[2*i+1],m-l+2))%mod;
}
void update(const int &u,const int &v,const ll &val) {
    update(1,1,n,u,v,val);
}
ii sum(int i,int l,int r,int u,int v,ll add) {
    if (l>v) return (zero);
    if (r<u) return (zero);
    if (l>r) return (zero);
    if (v<u) return (zero);
    if (u<=l && r<=v) {
        ll s0=(tre0[i]+(add*sumfib(0,r-l))%mod)%mod;
        ll s1=(tre1[i]+(add*sumfib(1,r-l+1))%mod)%mod;
        return (ii(s0,s1));
    }
    add=(add+lazy[i])%mod;
    int m=(l+r)/2;
    ii left=sum(2*i,l,m,u,v,add);
    ii right=sum(2*i+1,m+1,r,u,v,add);  
    if (m<u) return (right);
    if (m+1>v) return (left);
    ll s0,s1;
    s0=(left.x+value(right.x,right.y,m-max(l,u)+1))%mod;
    s1=(left.y+value(right.x,right.y,m-max(l,u)+2))%mod;
    return (ii(s0,s1));
}
ll sum(const int &u,const int &v) {
    return (sum(1,1,n,u,v,0LL).x);  
}
void answer(void) {
    int i,l,r,t;
    ll v;
    for (i=1;i<=n;i=i+1) {
        scanf("%I64d",&v);
        assign(i,v);
    }
    for (i=1;i<=n;i=i+1)
        assert(sum(i,i)==a[i]);
    for (i=1;i<=q;i=i+1) {
        scanf("%d",&t);
        if (t==1) {         
            scanf("%d",&l);
            scanf("%I64d",&v);           
            assign(l,v);
        }
        if (t==2) {         
            scanf("%d",&l);
            scanf("%d",&r);
        //  printf("Answering from %d to %d\n",l,r);
            printf("%I64d\n",sum(l,r));          
        }
        if (t==3) {         
            scanf("%d",&l);
            scanf("%d",&r);
            scanf("%I64d",&v);
        //  printf("Adding from %d to %d with %I64d\n",l,r,v);
            update(l,r,v);
        }
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    answer();
    return 0;
}