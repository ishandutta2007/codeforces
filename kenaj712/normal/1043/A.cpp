#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,maks=0,suma=0,b,k,pom;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        maks=max(maks,b);
        suma+=b;
    }
    k=maks;
    pom=a*maks-suma;
    while(pom<=suma)
    {
        pom+=a;
        k++;
    }
    cout<<k;
	return 0;
}