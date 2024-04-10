#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(a<=2*b+1)
    {
        cout<<1<<'\n'<<(a+1)/2;
        return 0;
    }
    int licz=0;
    licz+=a/(2*b+1);
    if(a%(2*b+1)==0)
    {
        int pom=b+1;
        cout<<licz<<'\n';
        while(pom<=a)
        {
            cout<<pom<<" ";
            pom+=2*b+1;
        }
    }
    else
    {
        cout<<licz+1<<'\n';
        int pom=(a-1)%(2*b+1);
        pom=min(pom,b);
        pom++;
        while(pom<=a)
        {
            cout<<pom<<" ";
            pom+=2*b+1;
        }
    }
	return 0;
}