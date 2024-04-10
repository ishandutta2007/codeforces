#include<cstdio>
#include<algorithm>
using namespace std;
int n,A,B,a[100005],Sum;

int main()
{
	//freopen("CF975B.in","r",stdin);
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),Sum+=a[i];
    if(n<=1){printf("0\n");return 0;}
    sort(a+2,a+1+n);
    if(a[1]*A/Sum>=B){printf("0\n");return 0;}
    for(int i=n;i>1;i--)
	{
        Sum-=a[i];
        if(a[1]*A/Sum>=B){printf("%d",n-i+1);break;}
    }
    return 0;
}