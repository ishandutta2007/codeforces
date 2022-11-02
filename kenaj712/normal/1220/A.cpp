#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    int licz1=0,licz2=0,licz3=0;
    cin>>a;
    char znak;
    for(int x=0;x<a;x++)
    {
        cin>>znak;
        if(znak=='z'||znak=='r')
            licz1++;
        else if(znak=='n')
            licz3++;
        else
            licz2++;
    }
    licz1/=2;
    while(licz3--)
        cout<<1<<" ";
    while(licz1--)
        cout<<0<<" ";
	return 0;
}