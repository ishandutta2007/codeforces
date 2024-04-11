//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    for(int i=1; i<=4; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ra = min(a,b), rb = min(c,d);
        if(ra+rb <= x)
        {
            printf("%d %d %d\n", i, ra, x-ra);
            return 0;
        }
    }
    printf("-1");
    return 0;
}