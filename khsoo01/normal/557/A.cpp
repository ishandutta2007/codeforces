#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[3][2],x[3],t;

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<3;i++) {
        for(j=0;j<2;j++) {
            scanf("%d",&a[i][j]);
        }
        x[i]+=a[i][0];
        n-=a[i][0];
    }
    for(i=0;i<3;i++) {
        t=min(n,a[i][1]-x[i]);
        x[i]+=t;
        n-=t;
        printf("%d ",x[i]);
    }
}