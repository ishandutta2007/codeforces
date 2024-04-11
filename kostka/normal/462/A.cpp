//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
char tab[MAXN][MAXN];
int n;

int da[] = {0,0,-1,1}, db[] = {1,-1,0,0};

bool onboard(int a, int b)
{
    return 0<=a && a<n && 0<=b && b<n;
}

bool check(int a, int b)
{
    int ile = 1;
    for(int i=0; i<4; i++)
    {
        int na = a+da[i], nb = b+db[i];
        if(onboard(na,nb) && tab[na][nb]=='o')
            ile++;
    }
    return ile%2;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", tab[i]);
    bool czy = true;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            czy &= check(i,j);
    puts(czy ? "YES" : "NO");
    return 0;
}