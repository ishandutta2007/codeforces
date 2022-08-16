#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e6+5;
ll cnt[maxn];
ll prod[maxn];
ll prefix[maxn];
int main()
{
	memset(cnt,0,sizeof cnt);
	memset(prod,0,sizeof prod);
	int n,x;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i = 1;i*i<maxn;i++)
		for(int j = i;i*j<maxn;j++){
			if(i==j)
				prod[i*i]+=(cnt[i]*(cnt[i]-1));
			else
				prod[i*j] += 2*cnt[i]*cnt[j];
		}
	prod[0] = 0;
	for(int i = 1;i<maxn;i++)
		prefix[i]  = prefix[i-1] + prod[i];
	int m;
	cin>>m;
	while(m--)
	{
		int p;
		scanf("%d",&p);
		printf("%lld\n",n*1ll*(n-1) - prefix[p-1]);
	}
}