#include<bits/stdc++.h>
using namespace std;
long long tab[10010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long x,d,n,pot,wyk,a,suma,popi,i;
	cin>>x>>d;
	suma=0;
	a=1;
	n=0;
	i=1;
	while(suma<x)
	{
		pot=1;
		wyk=0;
		while((pot-1)<=(x-suma))
		{
			pot*=2;
			wyk++;
		}
		pot/=2;
		wyk--;
		pot--;
		popi=i;
		for(;i<(popi+wyk);i++)
		{
			n++;
			tab[i]=a;
		}
		a+=d+1;
		suma+=pot;
	}
	cout<<n<<"\n";
	for(i=1;i<=n;i++)
		cout<<tab[i]<<" ";
	return 0;
}