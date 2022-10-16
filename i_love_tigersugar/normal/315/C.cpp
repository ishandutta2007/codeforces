#include<cstdio>
#define MAX   200200
typedef long long ll;
ll a[MAX];
ll k;
int n;
void init(void) {
    scanf("%d",&n);
    scanf("%I64d",&k);
    int i;
    for (i=1;i<=n;i=i+1) scanf("%I64d",&a[i]);
}
void process(void) {
    int fail=0;
    int succ=0;
    ll sum=0LL;
    ll cur;
    int i;
    for (i=1;i<=n;i=i+1) {
        cur=sum-a[i]*succ*(n-fail-succ-1);
        if (cur<k) {
            printf("%d\n",i);
            fail++;         
        }
        else {
            sum+=a[i]*succ;
            succ++;
        }
    }
}
int main(void) {
    init();
    process();
    return 0;
}