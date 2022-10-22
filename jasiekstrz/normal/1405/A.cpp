#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int tab[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,i;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>tab[i];
		for(i=n;i>=1;i--)
			cout<<tab[i]<<" ";
		cout<<"\n";
	}
	return 0;
}