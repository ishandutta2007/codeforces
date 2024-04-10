#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int b;
    string a;
    cin>>b>>a;
    long long licz1=1,licz2=1;
    for(int x=1;x<b;x++)
    {
        if(a[x]==a[x-1])
            licz1++;
        else
            break;
    }
    for(int x=b-2;x>=0;x--)
    {
        if(a[x]==a[x+1])
            licz2++;
        else
            break;
    }
    if(a[0]==a[b-1])
    {
        cout<<((licz1+1)*(licz2+1))%mod;
    }
    else
    {
        cout<<(licz1+licz2+1%mod);
    }
	return 0;
}