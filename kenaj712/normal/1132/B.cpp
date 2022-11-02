#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    long long suma=0;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        suma+=tab[x];
        tab[x]*=(-1);
    }
    sort(tab,tab+a);
    int t,b;
    cin>>t;
    while(t--)
    {
        cin>>b;
        cout<<suma+tab[b-1]<<'\n';
    }
	return 0;
}