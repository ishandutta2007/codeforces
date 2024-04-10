#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;
    if(a>b)
        swap(a,b);
    if(a==1)
    {
        if(b%2==0&&c==-1)
            cout<<0;
        else
            cout<<1;
        return 0;
    }
    long long pot=a-1;
    long long act=2,wynik=1;
    while(pot!=0)
    {
        if(pot%2==1)
            wynik=(wynik*act)%mod;
        act=(act*act)%mod;
        pot/=2;
    }
    pot=b-1;
    act=wynik;
    wynik=1;
    while(pot!=0)
    {
        if(pot%2==1)
            wynik=(wynik*act)%mod;
        act=(act*act)%mod;
        pot/=2;
    }
    if(c==-1&&(a%2!=b%2))
        wynik=0;
    cout<<wynik;
	return 0;
}