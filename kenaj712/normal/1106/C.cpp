#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
	for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    long long licz=0;
    for(int x=0;x<a/2;x++)
        licz+=(tab[x]+tab[a-x-1])*(tab[x]+tab[a-x-1]);
    cout<<licz;
	return 0;
}