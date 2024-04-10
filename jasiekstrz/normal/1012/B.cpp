#include<bits/stdc++.h>
using namespace std;
pair<int,int> tab[200010];
int FAU[200010];
bool byl[200010];
bool czy[200010];
int Find(int a)
{
	if(FAU[a]!=a)
		FAU[a]=Find(FAU[a]);
	return FAU[a];
}
void Union(int a,int b)
{
	FAU[Find(a)]=Find(b);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,q,w,i;
	cin>>n>>m>>q;
	for(i=1;i<=q;i++)
	{
		cin>>tab[i].first>>tab[i].second;
		czy[tab[i].first]=true;
	}
	sort(tab+1,tab+q+1);
	for(i=1;i<=m;i++)
		FAU[i]=i;
	for(i=2;i<=q;i++)
	{
		if(tab[i].first==tab[i-1].first)
			Union(tab[i].second,tab[i-1].second);
	}
	w=0;
	for(i=1;i<=m;i++)
	{
		if(!byl[Find(i)])
		{
			byl[Find(i)]=true;
			w++;
		}
	}
	w--;
	for(i=1;i<=n;i++)
	{
		if(!czy[i])
			w++;
	}
	cout<<w;
	return 0;
}