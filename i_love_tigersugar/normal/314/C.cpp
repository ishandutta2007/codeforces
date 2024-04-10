#include<cstdio>
#define MAX    1000007
typedef long long ll;
const ll mod=(ll)1e9+7;
int a[MAX];
ll f[MAX];
ll tree[MAX+7];
int prev[MAX+7];
int n;
void add(ll &x,const ll &y) {
    x=(x+y)%mod;
}
void update(int x,const ll &val) {
    while (1<=x && x<=MAX) {
        add(tree[x],val);
        x+=x&(-x);
    }   
}
ll sum(int x) {
    ll ret=0LL;
    while (1<=x && x<=MAX) {
        add(ret,tree[x]);
        x=x&(x-1);
    }
    return (ret);
}
void init(void) {
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i=i+1) scanf("%d",&a[i]); 
}
void process(void) {
    int i;
    ll t;
    ll res=0LL;
    for (i=1;i<=n;i=i+1) {
        f[i]=sum(a[i]);
        t=f[i];
        if (prev[a[i]]>0) t=(t-f[prev[a[i]]]+mod)%mod;
        else t=(t+1)%mod;
        t=(t*a[i])%mod;
        add(res,t);
        update(a[i],t);
        prev[a[i]]=i;
    }
    printf("%I64d",res);
}
int main(void) {
    init();
    process();
    return 0;
}