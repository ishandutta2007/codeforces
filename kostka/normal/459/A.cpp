//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

void wypisz(int a, int b, int c, int d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

int main()
{
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if(x1==x2)
    {
        int odl = y2-y1;
        wypisz(x1+odl, y1, x2+odl, y2);
    }
    else if(y1==y2)
    {
        int odl = x2-x1;
        wypisz(x1, y1+odl, x2, y2+odl);
    }
    else
    {
        if(abs(x2-x1) == abs(y2-y1))
            wypisz(x1,y2,x2,y1);
        else
            printf("-1");
    }
    return 0;
}