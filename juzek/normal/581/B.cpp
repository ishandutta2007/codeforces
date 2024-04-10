#include <bits/stdc++.h>
using namespace std;

int tab[100007];
int maxi[100007];

int main()
{
    int N;
    scanf("%d",&N);
    for (int i = 0;i < N;i++)
    {
        scanf("%d",&tab[i]);
    }
    for (int i = N-1;i >= 0;i--)
    {
        maxi[i] = max(tab[i],maxi[i+1]);
    }
    for (int i = 0;i < N;i++)
    {
        printf("%d ",max(0,maxi[i+1]-tab[i]+1));
    }
    return 0;
}