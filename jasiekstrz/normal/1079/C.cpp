#include<bits/stdc++.h>
using namespace std;
int w[100010];
int tab[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ost,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>tab[i];
	if(tab[2]>tab[1])
		ost=1;
	else if(tab[2]<tab[1])
		ost=5;
	else
		ost=3;
	w[1]=ost;
	tab[n+1]=tab[n];
	for(i=2;i<=n;i++)
	{
		if(tab[i+1]>tab[i])
		{
			if(tab[i-1]<tab[i])
				w[i]=w[i-1]+1;
			else if((tab[i-1]==tab[i])&&(w[i-1]==1))
				w[i]=2;
			else
				w[i]=1;
		}
		else if(tab[i+1]<tab[i])
		{
			if(tab[i-1]>tab[i])
				w[i]=w[i-1]-1;
			else if((tab[i-1]==tab[i])&&(w[i-1]==5))
				w[i]=4;
			else
				w[i]=5;
		}
		else
		{
			if(tab[i-1]<tab[i])
				w[i]=w[i-1]+1;
			else if(tab[i-1]>tab[i])
				w[i]=w[i-1]-1;
			else if(w[i-1]==3)
				w[i]=2;
			else 
				w[i]=3;
		}
		//cout<<i<<" "<<w[i]<<"\n";
		if((w[i]<1)||(w[i]>5))
		{
			cout<<"-1";
			return 0;
		}
	}
	for(i=1;i<=n;i++)
		cout<<w[i]<<" ";
	return 0;
}