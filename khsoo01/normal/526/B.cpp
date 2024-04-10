#include<cstdio>
#define max(X,Y)(X>Y?X:Y)
#define min(X,Y)(X<Y?X:Y)
long long i,n,a[9999],temp,sum;

int main()
{
    scanf("%lld",&n);
    temp=(1<<(n+1))-1;
    for(i=2;i<=temp;i++) {
        scanf("%lld",&a[i]);
    }
    for(i=temp;i>1;i-=2) {
        sum+=max(a[i],a[i-1])-min(a[i],a[i-1]);
        a[i/2]+=max(a[i],a[i-1]);
    }
    printf("%lld",sum);
}