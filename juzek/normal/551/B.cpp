#include <bits/stdc++.h>
using namespace std;

int ilA[1000];
int ilB[1000];
int ilC[1000];

int Na,Nb,Nc;

int kto()
{
    int odp1 = Na;
    int odp2 = Na;
    for (int i = 'a';i <= 'z';i++)
    {
        if (ilB[i] != 0)
            odp1 = min(odp1,ilA[i]/ilB[i]);
        if (ilC[i] != 0)
            odp2 = min(odp2,ilA[i]/ilC[i]);
    }
    //printf("%d %d\n",odp1,odp2);
    if (odp1 == 0 && odp2 == 0)
        return 2;
    if (odp1 >= odp2)
        return 0;
    else
        return 1;
}

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    Na = a.length();
    Nb = b.length();
    Nc = c.length();
    for (int i = 0;i < Na;i++)
        ilA[a[i]]++;
    for (int i = 0;i < Nb;i++)
        ilB[b[i]]++;
    for (int i = 0;i < Nc;i++)
        ilC[c[i]]++;


    int ter = 0;
    do
    {
        ter = kto();
        if (ter == 0)
        {
            for (int i = 'a';i <= 'z';i++)
                ilA[i] -= ilB[i];
            cout << b;
        }
        else if (ter == 1)
        {
            for (int i = 'a';i <= 'z';i++)
                ilA[i] -= ilC[i];
            cout << c;
        }

    } while (ter != 2);
    for (int i = 'a';i <= 'z';i++)
        for (int w = 0;w < ilA[i];w++)
            printf("%c",i);





    return 0;
}