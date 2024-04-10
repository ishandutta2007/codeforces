#include<bits/stdc++.h>
using namespace std;
int tab[20];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int pot=1,t=18;
    while(t--)
        pot*=2;
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    bool czy=false;
    for(int x=0;x<pot;x++)
    {
        int pom=x,suma=0,where=0;
        while(0==0)
        {
            if(pom%2==0)
                suma+=tab[where];
            else
                suma-=tab[where];
            where++;
            pom/=2;
            if(where==18)
                break;
        }
        while(suma<360)
            suma+=360;
        if(suma%360==0)
            czy=true;
    }
    if(czy==true)
        cout<<"YES";
    else
        cout<<"NO";

	return 0;
}