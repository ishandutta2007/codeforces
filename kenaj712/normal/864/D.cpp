#include <bits/stdc++.h>
using namespace std;
int tab[1000005];
int zlicz[1000005][2];
int zam[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
    for(int x=0;x<a;x++)
    {
       cin>>tab[x];
       zlicz[tab[x]][0]++;
    }
    int koniec=0,pomoc=0;
    for(int x=1;x<=a;x++)
        if(zlicz[x][0]==0)
        {
             koniec++;
             zam[pomoc]=x;
             pomoc++;
        }
    cout<<pomoc<<'\n';
    pomoc=0;
    for(int x=0;x<a;x++)
    {
        if(zlicz[tab[x]][0]==1&&zlicz[tab[x]][1]==0)
        {
            cout<<tab[x]<<" ";
            zlicz[tab[x]][0]--;
        }

        else
        {
                if(zam[pomoc]<tab[x])
                {
                    zlicz[tab[x]][0]--;
                    cout<<zam[pomoc]<<" ";
                    pomoc++;
                }
                else
                {
                    if(zlicz[tab[x]][1]==0)
                    {
                        cout<<tab[x]<<" ";
                        zlicz[tab[x]][0]--;
                        zlicz[tab[x]][1]=1;
                    }
                    else
                    {
                        cout<<zam[pomoc]<<" ";
                        pomoc++;
                        zlicz[tab[x]][0];
                    }

                }
        }
    }
	return 0;
}