//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

multiset <int> S, W;

int tab[207];

void test()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
        S.insert(-tab[i]);
    }
    int wyn = tab[0];
    for(int i=1; i<n; i++)
        wyn = max(tab[i], wyn);
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            int tmp = 0;
            for(int k=i; k<=j; k++)
            {
                W.insert(tab[k]);
                S.erase(S.find(-tab[k]));
            }
            for(int k=i; k<=j; k++)
                tmp += tab[k];
            int r = 0;
            for(multiset<int>::iterator it=W.begin(), jt = S.begin(); it!=W.end() && jt != S.end(); it++, jt++)
            {
                wyn = max(wyn, tmp);
                tmp -= (*it);
                tmp -= (*jt);
                r++;
                if(r==min(p,n))
                    break;
            }
            for(int k=i; k<=j; k++)
            {
                W.erase(W.find(tab[k]));
                S.insert(-tab[k]);
            }
            //printf("%d %d %d\n", i, j, wyn);
            wyn = max(wyn, tmp);
        }
    printf("%d\n", wyn);
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}