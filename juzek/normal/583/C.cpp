#include <bits/stdc++.h>
using namespace std;

map<int,int>m;

vector<int>liczby;

int tab[250007];

int main()
{
    int N;
    scanf("%d",&N);
    int M = N*N;
    for (int i = 0;i < M;i++)
    {
        scanf("%d",&tab[i]);
        m[tab[i]]++;
    }
    sort(tab,tab+M);
    for (int i = M-1;i >= 0;i--)
    {
        if (m[tab[i]] != 0)
        {
            m[tab[i]]--;
            for (int w = 0;w < liczby.size();w++)
                m[__gcd(tab[i],liczby[w])] -= 2;
            liczby.push_back(tab[i]);
        }
    }
    for (int i = 0;i < liczby.size();i++)
        printf("%d ",liczby[i]);
    return 0;
}