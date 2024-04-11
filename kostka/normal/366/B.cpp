//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
static int tab[MAXN];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", tab+i);
    int maks = 1000*1000*1000+7, res = 0;
    for(int i=0; i<k; i++)
    {
        int ile = 0;
        for(int j=i; j<n; j+=k)
            ile += tab[j];
        if(maks > ile)
        {
            maks = ile;
            res = i+1;
        }
    }
    printf("%d\n", res);
    return 0;
}