#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    long long suma=0,licz=0;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        suma+=b;
        if(b%2==1)
        {
            if(x%2==0)
                licz--;
            else
                licz++;
        }
    }
    licz=abs(licz);
    cout<<(suma-licz)/2;
	return 0;
}