#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,suma=0,suma2=0,licz=0;
    cin>>a;
    for(int x=0;x<4;x++)
    {
        cin>>b;
        suma+=b;
    }
    a--;
    while(a--)
    {
        suma2=0;
         for(int x=0;x<4;x++)
        {
            cin>>b;
            suma2+=b;
        }
        if(suma2>suma)
            licz++;
    }
    cout<<licz+1;
	return 0;
}