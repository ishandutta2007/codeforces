//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 300007;
int tab[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", tab+i);
    sort(tab, tab + n);
    long long wynik = 0;
    for(int i=0; i<n; i++)
        wynik += 1LL*(i+2)*tab[i];
    wynik -= tab[n-1];
    printf("%I64d\n", wynik);
    return 0;
}