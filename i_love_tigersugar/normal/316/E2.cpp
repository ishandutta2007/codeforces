#include<cassert>
#include<cstdio>
#define MAX   200200
typedef long long ll;
const ll mod=(ll)1e9;
ll a[MAX];
ll f[MAX];
ll s[MAX];
ll tre0[MAX<<2];
ll tre1[MAX<<2];
ll lazy[MAX<<2];
int n,q;
struct ans {
    ll s0,s1;
    int len;
    ans(){
        s0=0LL;
        s1=0LL;
        len=0;
    }
    ans(const ll &t0,const ll &t1,const int &l) {
        s0=t0;
        s1=t1;
        len=l;
    }   
};
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
    tre1[2*i]=(tre1[2*i]+(lazy[i]*sumfib(1,m-l+1))%mod)%mod;
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
ans sum(int i,int l,int r,int u,int v,ll add) { 
    if (l>v) return (ans());
    if (r<u) return (ans());
    if (l>r) return (ans());
    if (v<u) return (ans());
    if (u<=l && r<=v) {     
        ll s0=(tre0[i]+(add*sumfib(0,r-l))%mod)%mod;
        ll s1=(tre1[i]+(add*sumfib(1,r-l+1))%mod)%mod;      
        return (ans(s0,s1,r-l+1));
    }
    add=(add+lazy[i])%mod;
    int m=(l+r)/2;
    ans left=sum(2*i,l,m,u,v,add);
    ans right=sum(2*i+1,m+1,r,u,v,add); 
    ll s0=(left.s0+value(right.s0,right.s1,left.len))%mod;
    ll s1=(left.s1+value(right.s0,right.s1,left.len+1))%mod;        
    return (ans(s0,s1,left.len+right.len));
}
ll sum(const int &u,const int &v) {
    return (sum(1,1,n,u,v,0LL).s0); 
}
void assign(const int &x,const ll &val) {
    int i,l,m,r;
    ll old=0LL;
    i=1;
    l=1;
    r=n;
    while (true) {
        if (l==r) break;
        old=(old+lazy[i])%mod;
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
    old=(old+tre0[i])%mod;
    ll del=(val-old+mod)%mod;
    i=1;
    l=1;
    r=n;
    while (true) {
        tre0[i]=(tre0[i]+(del*f[x-l])%mod)%mod;
        tre1[i]=(tre1[i]+(del*f[x-l+1])%mod)%mod;
        if (l==r) return;
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
void answer(void) {
    int i,l,r,t;
    ll v;
    for (i=1;i<=n;i=i+1) {
        scanf("%I64d",&v);
        assign(i,v);
    }   
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
            printf("%I64d\n",sum(l,r));          
        }
        if (t==3) {         
            scanf("%d",&l);
            scanf("%d",&r);
            scanf("%I64d",&v);       
            update(l,r,v);          
        }
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("inp.txt","r",stdin);
#endif
    init();
    answer();
    return 0;
}