#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    if (n<=2) printf("1\n1");
    else if (n==3) printf("2\n1 3");
    else if (n==4) printf("4\n2 4 1 3");
    else
    {
        printf("%d\n",n);
        for (int i=1;i<=n;i+=2) printf("%d ",i);
        for (int i=2;i<=n;i+=2) printf("%d ",i);
    }
    return 0;
}