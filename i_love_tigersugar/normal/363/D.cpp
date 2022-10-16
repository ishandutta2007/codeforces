#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
typedef long long ll;
ll s;
int m,n;
ll b[MAX];
ll p[MAX];
template<class T>
    int min(const T &x,const T &y) {
        if (x<y) return (x); else return (y);
    }
bool cmp(const ll &a,const ll &b) {
    return (a>b);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%I64d",&s);
    int i;  
    for (i=1;i<=n;i=i+1) scanf("%I64d",&b[i]);
    for (i=1;i<=m;i=i+1) scanf("%I64d",&p[i]);
    sort(b+1,b+n+1,cmp);
    sort(p+1,p+m+1);
}
bool ok(const int &k) {
    if (k==0) return (true);
    if (k>n || k>m) return (false);
    ll req=0LL;
    int i,j;
    for (i=1;i<=k;i=i+1) {
        j=k-i+1;
        if (b[j]<p[i]) req+=p[i]-b[j];
    }
    return (req<=s);
}
void process(void) {
    int l=0;
    int r=n;
    int mid;
    while (true) {
        if (l==r) {
            mid=l;
            break;
        }
        if (r-l==1) {
            if (ok(r)) mid=r;
            else mid=l;
            break;
        }
        mid=(l+r)/2;
        if (ok(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d ",mid);
    if (mid==0) {
        printf("0");
        return;
    }
    int i;
    ll sum=0LL;
    for (i=1;i<=mid;i=i+1) sum+=p[i];   
    if (sum>=s) printf("%I64d",sum-s);
    else printf("0");
}
int main(void) {
    init();
    process();
    return 0;
}