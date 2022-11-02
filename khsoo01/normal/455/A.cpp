#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[100005],cnt[100005],dt[100005];

int main()
{
    long long i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(i=1;i<=100000;i++) {
        dt[i] = max(dt[i-1],dt[i-2]+cnt[i]*i);
    }
    printf("%lld",dt[100000]);
}