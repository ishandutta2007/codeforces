#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,suma=0,mini=0,maks=0;
    cin>>a;
    s.insert(0);
    for(int x=1;x<a;x++)
    {
        cin>>tab[x];
        suma+=tab[x];
        maks=max(maks,suma);
        mini=min(mini,suma);
        s.insert(suma);
        tab[x]=suma;
    }
    if(s.size()!=a||maks-mini!=a-1)
    {
        cout<<-1;
        return 0;
    }
    cout<<-mini+1<<" ";
    for(int x=1;x<a;x++)
    {
        cout<<tab[x]-mini+1<<" ";
    }
	return 0;
}