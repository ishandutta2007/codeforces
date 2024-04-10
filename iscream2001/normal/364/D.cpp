#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<cstring> 
#define ll long long

using namespace std;

const int maxn=1e6+10;
int n,siz;
ll d[maxn],a[maxn],cnt[maxn];

ll gcd(ll x,ll y)	// 
{
	return !y?x:gcd(y,x%y);
}

int random(int l,int r)	//l~r 
{
	return (ll)rand()*rand()%(r-l+1)+1;
}

void divide(ll x)	//x 
{
	siz=0;
	for(ll i=1; i*i<=x; i++)
		if(x%i==0)
		{
			d[++siz]=i;
			if(x/i!=i) d[++siz]=x/i;
		}
}

int main()
{
	srand(time(NULL));	// 
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%I64d",&a[i]);
	ll ans=0;
	for(int cas=1; cas<=10; cas++)
	{
		ll x=a[random(1,n)];
		divide(x);
		sort(d+1,d+1+siz);	// 
		memset(cnt,0,sizeof(cnt));
		for(int i=1; i<=n; i++)
		{
			int pos=lower_bound(d+1,d+1+siz,gcd(x,a[i]))-d;	//d>=gcd(x,a[i])
			cnt[pos]++;
		}
		for(int i=1; i<=siz; i++)
			for(int j=i+1; j<=siz; j++)
				if(d[j]%d[i]==0)
					cnt[i]+=cnt[j];
		for(int i=siz; i>=1; i--)
			if(cnt[i]*2>=n)	// 
			{
				ans=max(ans,d[i]);
				break;
			}
	}
	printf("%I64d\n",ans);
	return 0;
}