#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    if (n<=3) printf("NO\n");
    else 
    {
        printf("YES\n");
        bool even=n%2?false:true;
        //int m=even?4:5;
        for (int i=n;i>=6;i-=2)
        {
            printf("%d - %d = 1\n",i,i-1);
            printf("1 * %d = %d\n",i-2,i-2);
        }
        //if (n>=6) printf("1 * 1 = 1\n");
        if (even)
        {
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
        }
        else
        {
            printf("4 * 5 = 20\n");
            printf("2 + 3 = 5\n");
            printf("20 + 5 = 25\n");
            printf("25 - 1 = 24\n");
        }
    }
    return 0;
}