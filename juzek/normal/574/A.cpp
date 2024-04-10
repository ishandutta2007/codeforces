#include <bits/stdc++.h>
using namespace std;

int tab[100];

bool mn(int a,int b)
{
    return a>b;
}

int main()
{
    int N;
    scanf("%d",&N);
    int il;
    scanf("%d",&il);
    N--;
    for (int i = 0;i < N;i++)
    {
        scanf("%d",&tab[i]);
    }
    int odp = 0;
    sort(tab,tab+N,mn);
    int a;
    while (il <= tab[0])
    {
        il++;
        tab[0]--;
        odp++;
        a = 0;
        while (tab[a] < tab[a+1])
        {
            swap(tab[a],tab[a+1]);
            a++;
        }
    }
    printf("%d",odp);


}