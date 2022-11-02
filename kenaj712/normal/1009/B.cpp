#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    int licz1=0,licz0=0;
    bool czy=false;
    for(int x=0;x<a.size();x++)
    {
        if(a[x]=='1')
            licz1++;
        if(a[x]=='0'&&czy==false)
            licz0++;
        if(a[x]=='2')
            czy=true;
    }
    while(licz0--)
        cout<<0;
    while(licz1--)
        cout<<1;
    czy=false;
    for(int x=0;x<a.size();x++)
    {
        if(czy==false)
        {
            if(a[x]=='2')
            {
                czy=true;
                cout<<2;
            }

        }
        else
        {
            if(a[x]!='1')
                cout<<a[x];
        }
    }

	return 0;
}