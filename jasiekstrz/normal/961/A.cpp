#include<bits/stdc++.h>
using namespace std;
int tab[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,wczyt,mini,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>wczyt;
		tab[wczyt]++;
	}
	mini=1000000010;
	for(i=1;i<=n;i++)
	{
		mini=min(mini,tab[i]);
	}
	cout<<mini;
	return 0;
}