#include<cstdio>
#define MAX   111
typedef long long ll;
int n;
ll a[MAX];
ll p,q;
bool check(const int &i,const ll &p,const ll &q) {
    if (i==n) return (p%q==0 && p/q==a[n]);
    if (p%q==0 && p/q<=a[i]) return (false);
    if (p%q!=0 && p/q<a[i]) return (false);
    return (check(i+1,q,p-q*a[i]));
}
void process(void) {
    int i;
    scanf("%I64d",&p);
    scanf("%I64d",&q);
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1) scanf("%I64d",&a[i]);
    if (check(1,p,q)) printf("YES");
    else printf("NO");
}
int main(void) {
    process();
    return 0;
}