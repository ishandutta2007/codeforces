// Screw this ..
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
            {printf("FastestFinger\n"); continue;}
        if ((n & 1) || n == 2)
            {printf("Ashishgup\n"); continue;}
        int m = n, c = 0, cnt = 0;
        for (int i = 2; i * i <= m; i ++)
            if (m % i == 0)
            {
                while (m % i == 0)
                    m /= i, c ++;
                cnt ++;
            }
        if (m > 1)
            c ++, cnt ++;
        if (cnt == 1)
            {printf("FastestFinger\n"); continue;}
        if (n % 4 != 0 && c == 2)
            {printf("FastestFinger\n"); continue;}
        printf("Ashishgup\n");
    }
    return 0;
}