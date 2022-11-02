#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];

    sort(tab,tab+a);
    int pom=0,pom2=0;
    for(int x=1;x<a;x++)
    {
         if(tab[x]>tab[x-1]&&tab[x-1]+b>=tab[x])
            pom=pom+1+pom2;
         if(tab[x-1]==tab[x])
            pom2++;
        else
            pom2=0;

    }
    cout<<a-pom;

	return 0;
}