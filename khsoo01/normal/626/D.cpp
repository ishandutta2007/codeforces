#include<cstdio>
long long n,a[2005],dt[5005],tw[10005],ans;

int main()
{
    long long i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%lld",&a[i]);
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(a[i]<a[j]) {
                dt[a[j]-a[i]]++;
            }
        }
    }
    for(i=1;i<=5000;i++) {
        for(j=1;j<=5000;j++) {
            tw[i+j] += dt[i]*dt[j];
        }
    }
    for(i=1;i<=5000;i++) {
        for(j=1;j<i;j++) {
            ans += dt[i]*tw[j];
        }
    }
    printf("%.12lf",((double)ans)/((double)n*(n-1)/2*n*(n-1)/2*n*(n-1)/2));
}