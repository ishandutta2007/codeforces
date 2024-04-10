#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    int licz1[2],licz2[2];
    licz1[0]=0;
    licz1[1]=0;
    licz2[0]=0;
    licz2[1]=0;
    cin>>a>>b;
    while(a--)
    {
        cin>>c;
        licz1[c%2]++;
    }
    while(b--)
    {
        cin>>c;
        licz2[c%2]++;
    }
    cout<<min(licz1[0],licz2[1])+min(licz1[1],licz2[0]);
	return 0;
}