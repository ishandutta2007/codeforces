#include <bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a-c>b||c>b||(2*c>b&&d>=3)||(2*(a-c)>b&&d>=2))
    {
        cout<<-1;
        return 0;
    }
    int pom=0,pom2=0;
    while(d!=0)
    {
        if(pom2%2==0)
        {
            tab[pom]+=c;
            pom++;
            tab[pom]+=(a-c);
        }
        else
        {
            tab[pom]+=(a-c);
             pom++;
           tab[pom]+=c;
        }

        d--;
        pom2++;
    }
    int fuel=b,koniec=0;
    for(int x=0;x<=pom;x++)
    {
        if(fuel>=tab[x])
            fuel-=tab[x];
        else
        {
            koniec++;
            fuel=b;
            fuel-=tab[x];
        }
    }
    cout<<koniec;
	return 0;
}