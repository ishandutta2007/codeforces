#include<bits/stdc++.h>
using namespace std;
int n;
int tab[110];
int wyn[110];
bool czy(int s)
{
	int x,y,i;
	x=tab[1];
	y=tab[1];
	for(i=2;i<n;i++)
	{
		if(tab[i]-y>s)
			return false;
		else if(tab[i]-x>s)
			y=tab[i];
		else
		{
			x=y;
			y=tab[i];
		}
	}
	if(tab[n]-x>s)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x,y,p,k,s,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>tab[i];
	sort(tab+1,tab+n+1);
	p=0;
	k=tab[n]-tab[1];
	while(p<k)
	{
		s=(p+k)/2;
		if(czy(s))
			k=s;
		else
			p=s+1;
	}
	s=p;
	wyn[1]=tab[1];
	x=tab[1];
	y=tab[1];
	k=n;
	p=2;
	for(i=2;i<=n;i++)
	{
		if(((y<x)&&(tab[i]-y<=s))||(tab[i]-x>s))
		{
			wyn[k]=tab[i];
			k--;
			y=tab[i];
		}
		else
		{
			wyn[p]=tab[i];
			p++;;
			x=tab[i];
		}
	}
	for(i=1;i<=n;i++)
		cout<<wyn[i]<<" ";
	return 0;
}