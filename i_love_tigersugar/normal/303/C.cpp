#include<cstdio>
#define MAXV   1000010
#define MAXN   5050
int a[MAXN];
int diff[MAXV+10];
int mod[MAXV+10];
int n,k;
int abs(const int &x) {
    if (x<0) return (-x); else return (x);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&k);
    int i,j;
    for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
    for (i=1;i<=n;i=i+1)
        for (j=i+1;j<=n;j=j+1)
            diff[abs(a[i]-a[j])]++;
}
bool ok(const int &m) {
    int cnt=0;
    int req=0;
    bool ret=true;
    int i,j;
    for (i=m;i<=MAXV;i=i+m) {
        cnt+=diff[i];
        if (cnt>k*(k+1)/2) return (false);
    }
    for (i=1;i<=n;i=i+1) {
        if (mod[a[i]%m]>0) req++;
        if (req>k) {
            ret=false;
            break;
        }
        mod[a[i]%m]++;
    }
    for (j=1;j<i;j=j+1) mod[a[j]%m]--;
    return (ret);
}
void process(void) {
    int ans=1;
    while (!ok(ans)) ans++;
    printf("%d",ans);
}
int main(void) {
    init();
    process();
    return 0;
}