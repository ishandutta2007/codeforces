//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int tab[MAXN], res[MAXN];

int a = MAXN, b = -1;

bool check(int n)
{
    sort(res, res + n);
    for(int i=0; i<n; i++)
    {
        if(res[i] != tab[i])
        {
           a = min(a,i);
           b = max(b,i);
        }
    }
    if(b==-1)
    {
        a = 0;
        b = 0;
    }
    reverse(tab+a, tab+b+1);
    for(int i=0; i<n; i++)
    {
        if(res[i] != tab[i])
            return false;
    }
    return true;
}

void test()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
        res[i] = tab[i];
    }
    if(check(n))
    {
        puts("yes");
        printf("%d %d\n", a+1, b+1);
    }
    else
        puts("no");
    
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}