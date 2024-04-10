#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    if(a>b)
    {
        cout<<0;
        return 0;
    }
    long long wynik=1;
    for(int x=0;x<a;x++)
        for(int y=x+1;y<a;y++)
            wynik=(wynik*abs(tab[x]-tab[y]))%b;
    cout<<wynik%b;
	return 0;
}