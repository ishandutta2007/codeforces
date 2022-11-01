#include <bits/stdc++.h>
using namespace std;

int bitcount(int a)
{
    int odp = 0;
    while (a)
    {
        if (a&1)
            odp++;
        a >>= 1;
    }
    return odp;
}

int main()
{
    int N;
    scanf("%d",&N);
    printf("%d",bitcount(N));
    return 0;
}