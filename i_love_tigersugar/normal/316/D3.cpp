#include<cstdio>
#define MAX   1000010
typedef long long ll;
const ll mod=(ll)1e9+7;
ll f[MAX];
int n,c;
void process(void) {
    scanf("%d",&n);
    int i,t;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&t);
        if (t==1) c++;
    }
    f[0]=1LL;
    f[1]=1LL;
    for (i=2;i<=c;i=i+1)
        f[i]=(f[i-1]+f[i-2]*(i-1))%mod;
    ll res=f[c];
    for (i=c+1;i<=n;i=i+1) res=(res*i)%mod;
    printf("%I64d",res);
}
int main(void) {
    process();
    return 0;
}