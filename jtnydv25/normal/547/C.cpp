#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn =5e5+2;
#define vi vector<int>
#define pb push_back
int factor[maxn],mu[maxn],cnt[maxn];
vi divs[maxn];
void pre()
{
	memset(factor,0,sizeof factor);
	for(int i = 2;i*i<maxn;i++)
		if(!factor[i])
			for(int j = i*i;j<maxn;j+=i)
				factor[j] = i;
	mu[1] = 1;
	for(int i = 2;i<maxn;i++)
	{
		int p;
		if(!factor[i])
			p = i;
		else
			p = factor[i];
		int j = i/p;
		if(j%p == 0)
			mu[i] = 0;
		else
			mu[i] = mu[j]*(-1);
	}		
	for(int i = 2;i<maxn;i++)
		if(mu[i]!=0)
			for(int j = i;j<maxn;j+=i)
				divs[j].pb(i);
}
bool present[maxn];
int a[maxn];
ll C(int n)
{
	return (n*1ll*(n-1))/2;
}
int main()
{
	pre();
	memset(cnt,0,sizeof cnt);
	int tcount = 0;
	memset(present,0,sizeof present);
	ll query = 0;
	int q,n;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	while(q--)
	{
		int k;
		cin>>k;
		if(!present[k])
		{
			present[k] = 1;
			tcount ++ ;
			query += C(tcount)-C(tcount-1);
			int num = a[k];
			for(int i = 0;i<divs[num].size();i++)
			{
				int d = divs[num][i];
				cnt[d]++;
				query += mu[d]*(C(cnt[d])-C(cnt[d]-1));
			}
		}
		else
		{
			present[k] = 0;
			tcount -- ;
			query += C(tcount)-C(tcount+1);
			int num = a[k];
			for(int i = 0;i<divs[num].size();i++)
			{
				int d = divs[num][i];
				cnt[d]--;
				query += mu[d]*(C(cnt[d])-C(cnt[d]+1));
			}
		}
		cout<<query<<endl;
	}
	return 0;
}