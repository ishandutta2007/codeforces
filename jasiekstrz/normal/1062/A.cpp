#include<bits/stdc++.h>
using namespace std;
int tab[210];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ile,w,i;
	cin>>n;
	ile=0;
	w=0;
	tab[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>tab[i];
		if(tab[i]==tab[i-1]+1)
			ile++;
		else
		{
			w=max(w,ile-1);
			ile=0;
		}
	}
	if(tab[n]==1000)
		ile++;
	w=max(w,ile-1);
	cout<<w;
	return 0;
}