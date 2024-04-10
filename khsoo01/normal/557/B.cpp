#include<cstdio>
#include<algorithm>
#define min(X,Y)(X<Y?X:Y)
int n,w,a[200005];
double q,r,e;

int main()
{
    int i,j;
    scanf("%d%d",&n,&w);
    for(i=0;i<2*n;i++) {
        scanf("%d",&a[i]);
    }
    std::sort(a,a+2*n);
    q=a[0];
    r=a[n];
    e=w;
    q=q*3*n;
    r=r*1.5*n;
    printf("%lf",min(q,min(r,e)));
}