#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int tab[300010];
unordered_map<int,int> cnt;
inline pair<long long,int> solve(int n)
{
	pair<long long,int> tmp={0,0};
	for(int j=0;j<=30;j++)
	{
		long long ans[2]={0,0};
		cnt.clear();
		for(int i=1;i<=n;i++)
		{
			if(tab[i]&(1<<j))
				ans[1]+=cnt[(tab[i]>>j)^1];
			else
				ans[0]+=cnt[(tab[i]>>j)^1];
			cnt[(tab[i]>>j)]++;
		}
		if(ans[0]<=ans[1])
		{
			tmp.fi+=ans[0];
		}
		else
		{
			tmp.fi+=ans[1];
			tmp.se^=(1<<j);
		}
	}
	return tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tab[i];
	}
	pair<long long,int> xd=solve(n); 
	cout<<xd.fi<<" "<<xd.se<<"\n";
	return 0;
}