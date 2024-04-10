#include<cstdio>
typedef long long ll;
ll m,n,x,y,a,b,u,v;
ll min(const ll &x,const ll &y) {
    if (x<y) return (x); else return (y);
}
ll max(const ll &x,const ll &y) {
    if (x>y) return (x); else return (y);
}
ll gcd(ll a,ll b) {
    while (true) {
        if (a==0LL) return (b);
        if (b==0LL) return (a);
        if (a>b) a=a%b; else b=b%a;
    }
}   
void init(void) {
    scanf("%I64d",&m);
    scanf("%I64d",&n);
    scanf("%I64d",&x);
    scanf("%I64d",&y);
    scanf("%I64d",&a);
    scanf("%I64d",&b);
    ll t=gcd(a,b);
    a=a/t;
    b=b/t;
}
void findsize(void) {
    ll l,r,k;
    l=1LL;
    r=min(m,n);
    while (true) {
        if (l==r) {
            k=r;
            break;
        }
        if (r-l==1) {
            if (r*a<=m && r*b<=n) k=r;
            else k=l;
            break;
        }
        k=(l+r)/2;
        if (k*a<=m && k*b<=n) l=k;
        else r=k-1;
    }
    u=k*a;
    v=k*b;
}
ll dx(const ll &x1) {
    return (x1*2-x*2+u)*(x1*2-x*2+u);
}
ll dy(const ll &y1) {
    return (y1*2-y*2+v)*(y1*2-y*2+v);
}
ll findx(void) {
    ll l=max(0LL,x-u);
    ll r=min(m-u,x);
    ll i,k1,k2;
    while (true) {
        if (r-l+1<=5) {
            k1=l;
            for (i=l;i<=r;i=i+1)
                if (dx(k1)>dx(i)) k1=i;
            return (k1);
        }
        k1=(l*2+r)/3;
        k2=(l+r*2)/3;
        if (dx(k1)<=dx(k2)) r=k2;
        if (dx(k1)>=dx(k2)) l=k1;       
    }
}
ll findy(void) {
    ll l=max(0LL,y-v);
    ll r=min(n-v,y);
    ll i,k1,k2;
    while (true) {
        if (r-l+1<=5) {
            k1=l;
            for (i=l;i<=r;i=i+1)
                if (dy(k1)>dy(i)) k1=i;
            return (k1);
        }
        k1=(l*2+r)/3;
        k2=(l+r*2)/3;
        if (dy(k1)<=dy(k2)) r=k2;
        if (dy(k1)>=dy(k2)) l=k1;
    }   
}
void print(void) {
    findsize();
    ll x1=findx();
    ll y1=findy();
    printf("%I64d %I64d %I64d %I64d",x1,y1,x1+u,y1+v);
}
int main(void) {
    init();
    print();
    return 0;
}