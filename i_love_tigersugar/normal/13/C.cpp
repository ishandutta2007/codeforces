#include<bits/stdc++.h>
#define MAX   5050
using namespace std;
typedef long long ll;
ll a[MAX];
ll b[MAX];
ll f[3][MAX];
int n;
ll min(const ll &x,const ll &y) {
    if (x<y) return (x); else return (y);
}
ll labs(const ll &x) {
    if (x<0LL) return (-x); else return (x);
}
void init(void) {
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1) {
        scanf("%I64d",&a[i]);
        b[i]=a[i];
    }
    sort(&b[1],&b[n+1]);
}
void optimize(void) {
    int i,j;
    f[1][1]=labs(a[1]-b[1]);
    for (i=2;i<=n;i=i+1)
        f[1][i]=min(f[1][i-1],labs(a[1]-b[i]));
    for (i=2;i<=n;i=i+1) {
        f[i%2][1]=f[(i-1)%2][1]+labs(a[i]-b[1]);
        for (j=2;j<=n;j=j+1)
            f[i%2][j]=min(f[i%2][j-1],f[(i-1)%2][j]+labs(a[i]-b[j]));
    }
    printf("%I64d",f[n%2][n]);
}
int main(void) {
    init();
    optimize();
    return 0;   
}