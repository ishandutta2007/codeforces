#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=1000005;

int n,p[MAXN];
LL sum1_pos=0,sum1_neg=0,sum2_pos=0,sum2_neg=0;
int cnt1_pos=0,cnt1_neg=0,cnt2_pos=0,cnt2_neg=0;
vector <int> G[MAXN];

LL cal(int k)
{
	LL ret=0;
	ret+=sum1_pos-(LL)k*cnt1_pos;
	ret+=(LL)k*cnt1_neg+sum1_neg;
	ret+=sum2_pos-(LL)(k-n)*cnt2_pos;
	ret+=(LL)(k-n)*cnt2_neg+sum2_neg;
	return ret;
}

void del(int v,int d)
{
	if (v+d<n)
	{
		if (p[v]>v+d)
		{
			sum1_pos-=p[v]-v;
			cnt1_pos--;
		}
		else
		{
			sum1_neg-=v-p[v];
			cnt1_neg--;
		}
	}
	else
	{
		int x=(v+d)%n;
		if (p[v]>x)
		{
			sum2_pos-=p[v]-v;
			cnt2_pos--;
		}
		else
		{
			sum2_neg-=v-p[v];
			cnt2_neg--;
		}
	}
}

void add(int v,int d)
{
	if (v+d<n)
	{
		if (p[v]>v+d)
		{
			sum1_pos+=p[v]-v;
			cnt1_pos++;
			G[p[v]-v].pb(v);
		}
		else
		{
			sum1_neg+=v-p[v];
			cnt1_neg++;
			G[n-v].pb(v);
		}
	}
	else
	{
		int x=(v+d)%n;
		if (p[v]>x)
		{
			sum2_pos+=p[v]-v;
			cnt2_pos++;
			if (d+p[v]-x<n) G[d+p[v]-x].pb(v);
		}
		else
		{
			sum2_neg+=v-p[v];
			cnt2_neg++;
			if (d+n-x<n) G[d+n-x].pb(v);
		}
	}
}

void update(int v,int k)
{
	del(v,k-1);
	add(v,k);
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
		if (p[i]>i)
		{
			sum1_pos+=p[i]-i;
			cnt1_pos++;
			G[p[i]-i].pb(i);
		}
		else
		{
			sum1_neg+=i-p[i];
			cnt1_neg++;
			G[n-i].pb(i);
		}
	}
	LL ans=LLONG_MAX;
	int ansid=0;
	for (int k=0;k<n;k++)
	{
		for (int i=0;i<G[k].size();i++)
		{
			int v=G[k][i];
			update(v,k);
		}
		LL t=cal(k);
		if (t<ans)
		{
			ans=t;
			ansid=k;
		}
	}
	printf("%lld %d",ans,ansid);
	return 0;
}