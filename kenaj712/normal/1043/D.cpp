#include<bits/stdc++.h>
using namespace std;
int tab[100005][12];
int where[100005][10];
bool odw[100005];
long long suma,licz;
int b;
void f(int a)
{
    licz++;
    odw[a]=true;
    int pom=tab[where[a][0]+1][0];
    bool czy=false;
    if(pom!=0&&odw[pom]==false)
    {
        for(int y=0;y<b;y++)
        {
            if(tab[where[a][y]+1][y]!=pom)
                czy=true;
        }
        if(czy==false)
            f(pom);
    }
    czy=false;
    if(where[a][0]!=0)
    {
        pom=tab[where[a][0]-1][0];
        if(odw[pom]==false)
        {
            for(int y=0;y<b;y++)
            {
                if(where[a][y]!=0)
                {
                    if(tab[where[a][y]-1][y]!=pom)
                        czy=true;
                }
                else
                    czy=true;

            }
            if(czy==false)
                f(pom);
        }
    }

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        for(int y=0;y<a;y++)
        {
            cin>>tab[y][x];
            where[tab[y][x]][x]=y;
        }
    }
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==false)
        {
            licz=0;
            f(x);
            suma+=licz*(licz+1)/2;
        }
    }
    cout<<suma;
	return 0;
}