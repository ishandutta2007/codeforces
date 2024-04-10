#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
long long zero;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,pom,suma=0,mini=0,out=0;
    cin>>b>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        suma+=tab[x];
        mini=min(mini,suma);
    }
    for(int x=0;x<a;x++)
    {
        tab[x+a]=tab[x];
        tab[x+2*a]=tab[x];
        tab[x+3*a]=tab[x];
    }
    pom=b-abs(mini);
    if(pom>0&&suma>=0)
    {
        cout<<-1;
        return 0;
    }
    if(suma!=0)
        out=max(zero,(pom/abs(suma)));
    b+=(suma*out);
    out*=a;
    for(int x=0;x==x;x++)
    {
        if(b<=0)
        {
            cout<<out;
            return 0;
        }
        out++;
        b+=tab[x];

    }
	return 0;
}