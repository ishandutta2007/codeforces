#include<bits/stdc++.h>
using namespace std;
int tab[100010];
bool czy[100010];
int pref[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,sum,maks,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>tab[i];
	sum=0;
	for(i=1;i<=n;i++)
	{
		cin>>czy[i];
		pref[i]=pref[(i-1)];
		if(czy[i]==1)
			sum+=tab[i];
		else
			pref[i]+=tab[i];
	}
	maks=0;
	for(i=1;i<=(n-k+1);i++)
	{
		maks=max(maks,(sum+pref[i+k-1]-pref[i-1]));
	}
	cout<<maks;
	return 0;
}