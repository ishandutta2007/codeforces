#include<bits/stdc++.h>
using namespace std;
vector<long long> tab[100010];
long long pref[100010];
long long w[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,m,d,a,b,wyn,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		tab[a].push_back(b);
	}
	for(i=1;i<=m;i++)
	{
		sort(tab[i].begin(),tab[i].end());
		reverse(tab[i].begin(),tab[i].end());
		d=tab[i].size();
		if(d==0)
			continue;
		pref[0]=tab[i][0];
		if(pref[0]<=0)
			continue;
		else
			w[0]+=pref[0];
		for(j=1;j<d;j++)
		{
			pref[j]=pref[j-1]+tab[i][j];
			if(pref[j]<=0)
				break;
			w[j]+=pref[j];
		}
	}
	wyn=0;
	for(i=0;i<=n;i++)
		wyn=max(wyn,w[i]);
	cout<<wyn;
	return 0;
}