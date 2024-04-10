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
void die(string S){puts(S.c_str());exit(0);}
int cnt[1010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<k;i++)
			cnt[i]=0;
		ll res=0;
		while(n--)
		{
			ll x;
			scanf("%lld",&x);
			res+=x/k;
			cnt[x%k]++;
		}
		int p=k-1;
		for(int i=1;i<=(k-1)/2;i++)
		{
			while(p+i>=k&&cnt[i])
			{
				int x=min(cnt[p],cnt[i]);
				cnt[i]-=x;
				cnt[p]-=x;
				res+=x;
				if(!cnt[p])
					p--;
			}
		}
		int sum=0;
		for(int i=(k+1)/2;i<k;i++)
			sum+=cnt[i];
		cout<<res+sum/2<<endl;
	}
	return 0;
}