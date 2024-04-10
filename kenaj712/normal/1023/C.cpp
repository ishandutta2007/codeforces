#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,licz=0,licz1=0,licz2=0;
    cin>>a>>b;
    string tab;
    cin>>tab;
    for(int x=0;x<a;x++)
    {
        if(tab[x]=='(')
        {
            if(licz1<b/2)
            {
                cout<<'(';
                licz++;
                licz1++;
            }
        }
        else
        {
            if(licz2<licz1)
            {
                cout<<')';
                licz2++;
                licz++;
            }
        }
        if(licz==b)
            return 0;
    }
	return 0;
}