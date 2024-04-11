#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100007;
int tab[MAXN];

int main()
{
    int k, n, zmienna=1;
    scanf ("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &k);
        if (k>=tab[zmienna-1]) 
        {
            tab[zmienna]=k;
            zmienna++;
            continue;
        }
        else
        {
            int *w = upper_bound(tab, tab+zmienna, k);
            tab[w-tab] = k;
        }
    }
    printf ("%d", --zmienna);          
    return 0;                    
}