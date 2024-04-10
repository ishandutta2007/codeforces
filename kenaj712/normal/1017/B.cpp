#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int c;
    string a,b;
    cin>>c>>a>>b;
    long long licz1=0,licz2=0,licz3=0,licz4=0;
    for(int x=0;x<c;x++)
    {
        if(a[x]=='0')
            licz1++;
        if(a[x]=='1')
            licz2++;
        if(a[x]=='0'&&b[x]=='0')
            licz3++;
        if(a[x]=='1'&&b[x]=='0')
            licz4++;
    }
    cout<<licz3*licz2+licz4*licz1-licz3*licz4;
	return 0;
}