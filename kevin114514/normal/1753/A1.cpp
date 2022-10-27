//Author: Kevin5307
#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int a[200200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(i%2)
				sum+=a[i];
			else	sum-=a[i];
		}
		if(sum>=0)
			for(int i=1;i<=n;i++)
				a[i]*=-1;
		else
			sum*=-1;
		vector<pii> vec;
		for(int i=2;i<=n;i+=2)
			if(a[i]==0||(a[i]>0&&sum>=a[i]*2))
			{
				sum-=a[i]*2;
				vec.pb(mp(i,i));
			}
		vector<int> vect;
		vector<int> con;
		if(n%2)
			vec.pb(mp(n+1,n+1));
		int m=sz(vec);
		for(int i=1;i<m;i++)
		{
			int s=0;
			int mx=0,p=vec[i-1].second;
			for(int j=vec[i-1].second+1;j<vec[i].first;j++)
			{
				if(j%2==0)
					s+=a[j]*2;
				else	s-=a[j]*2;
				if((j-vec[i-1].second)%2==0)
				{
					if(s>mx&&s<=sum)
					{
						mx=s;
						p=j;
					}
				}
			}
			if(s>mx&&s<=sum)
			{
				con.pb(i);
				sum-=s;
			}
			else if(mx<=sum)
			{
				sum-=mx;
				vec[i-1].second=p;
			}
		}
		for(auto x:con)
		{
			vec[x].first=vec[x-1].first;
			vec[x-1]=mp(-1,-1);
		}
		vector<pii> nvec;
		for(auto pr:vec)
			if(pr.first>=0&&pr.first<=n)
				nvec.pb(pr);
		if(sum)
		{
			puts("-1");
			continue;
		}
		if(!sz(nvec))
		{
			printf("1\n");
			printf("1 %d\n",n);
			continue;
		}
		int tot=sz(nvec)*2;
		if(nvec.back().second<n)
			tot++;
		printf("%d\n",tot);
		for(int i=0;i<sz(nvec);i++)
		{
			if(i)
				printf("%d %d\n",nvec[i-1].second+1,nvec[i].first-1);
			else	printf("%d %d\n",1,nvec[i].first-1);
			printf("%d %d\n",nvec[i].first,min(n,nvec[i].second));
		}
		if(nvec.back().second<n)
			printf("%d %d\n",nvec.back().second+1,n);
	}
	return 0;
}