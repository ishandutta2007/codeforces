#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5;
int t[N+10];
pair<int,int> tab[N+10];
long long solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		tab[i]={t[i]+i,i};
	}
	sort(tab+1,tab+n+1);
	reverse(tab+1,tab+n+1);
	for(int i=1;i<=k;i++)
		t[tab[i].se]=0;
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]==0)
			cnt++;
		else
			ans+=cnt+t[i];
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		cout<<solve()<<"\n";
	return 0;
}