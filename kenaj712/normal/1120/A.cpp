#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int licz1[1000005];
int licz2[1000005];
bool block[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d,e;
    cin>>a>>b>>c>>d;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    int pom=a-b*c+b;
    for(int x=1;x<=d;x++)
    {
        cin>>e;
        licz2[e]++;
    }
    int licz=0;
    for(int x=1;x<=pom;x++)
    {
        licz1[tab[x]]++;
        if(licz1[tab[x]]<=licz2[tab[x]])
            licz++;

    }
    int xd=pom-b;
    for(int x=1;x<=a;x+=b)
    {
        if(licz>=d)
        {
            cout<<pom-b<<'\n';
            for(int y=x;y<=pom+x-1;y++)
            {
                if(licz2[tab[y]]>0)
                    licz2[tab[y]]--;
                else if(xd>0)
                {
                    cout<<y<<" ";
                    xd--;
                }

            }
            return 0;
        }
        for(int y=x;y<x+b;y++)
        {
            licz1[tab[y]]--;
            if(licz1[tab[y]]<licz2[tab[y]])
                licz--;
        }
        for(int y=x+pom;y<x+b+pom;y++)
        {
            licz1[tab[y]]++;
            if(licz1[tab[y]]<=licz2[tab[y]])
                licz++;
        }


    }
    cout<<-1;
	return 0;
}