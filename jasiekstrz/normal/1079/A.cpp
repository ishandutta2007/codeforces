#include<bits/stdc++.h>
using namespace std;
int tab[110];
int ile[110];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,m,x,w,i;
	cin>>n>>k;
	m=0;
	for(i=1;i<=n;i++)
	{
		cin>>tab[i];
		ile[tab[i]]++;
		m=max(ile[tab[i]],m);
	}
	x=k*((m+k-1)/k);
	w=0;
	for(i=1;i<=100;i++)
	{
		if(ile[i]!=0)
			w+=x-ile[i];
	}
	cout<<w;
	return 0;
}