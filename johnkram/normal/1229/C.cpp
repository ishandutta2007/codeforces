#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
#define P 1000000007
vector<int> d[MAXN];
ll ans;
int n,m,q,i,j,in[MAXN],out[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		if(i>j)i^=j^=i^=j;
		in[i]++;
		out[j]++;
		d[i].push_back(j);
	}
	for(i=1;i<=n;i++)ans+=(ll)in[i]*out[i];
	cout<<ans<<endl;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&i);
		for(auto x:d[i])
		{
			out[x]--;
			ans+=out[x]-in[x];
			in[x]++;
			d[x].push_back(i);
		}
		ans-=(ll)in[i]*out[i];
		out[i]+=in[i];
		in[i]=0;
		d[i].clear();
		cout<<ans<<endl;
	}
	return 0;
}