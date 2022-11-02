#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    long long suma=0,pom1,pom2,pom3;
    for(int x=1;x<=a;x++)
    {
        if(tab[x]==tab[x-1])
            continue;
        if(tab[x-1]>tab[x])
        {
            pom3=tab[x-1]-1;
            pom2=tab[x];
            pom1=1;
        }
        else
        {
            pom1=tab[x-1]+1;
            pom2=tab[x];
            pom3=a;
        }
        if(pom1>pom3)
            continue;
        suma+=(pom2-pom1+1)*(pom3-pom2+1);
    }
    cout<<suma;
	return 0;
}