//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int tab[107];

void test()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i=0; i<n; i++)
        scanf("%d", &tab[i]);
    sort(tab, tab + n);
    int suma = 0;
    for(int i=0; i<n-1; i++)
        suma += tab[i];
    puts((suma <= s) ? "YES" : "NO");
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}