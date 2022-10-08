//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
bool tab[MAXN][MAXN];
int n, m;

int check(int a, int b)
{
    if((b-a)%2)
        return b-a;
    int med = (b-a)/2;
    for(int i=0; i<med; i++)
    {
        for(int j=0; j<m; j++)
            if(tab[i][j] != tab[b-i-1][j])
                return b-a;
    }
    return check(a,med);
}

void test()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &tab[i][j]);
    printf("%d\n", check(0,n));
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}