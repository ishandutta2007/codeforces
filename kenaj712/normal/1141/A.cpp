#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,licz=0;
    cin>>a>>b;
    if(b%a!=0)
    {
        cout<<-1;
        return 0;
    }
    b/=a;
    while(b%2==0)
    {
        licz++;
        b/=2;
    }
    while(b%3==0)
    {
        licz++;
        b/=3;
    }
    if(b!=1)
    {
        cout<<-1;
        return 0;
    }
    cout<<licz;
	return 0;
}