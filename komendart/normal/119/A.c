#include <stdio.h>
int gcd(int a, int b)
{
    while(b != 0)
    {
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
int main()
{
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    while(1)
    {
        if(n == 0 || (n = n - gcd(a, n)) < 0)
        {
            printf("1\n");
            return 0;
        }
        if(n == 0 || (n = n - gcd(b, n)) < 0)
        {
            printf("0\n");
            return 0;
        }
    }
}