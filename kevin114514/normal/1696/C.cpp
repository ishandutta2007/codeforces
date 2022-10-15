#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
signed main()
{
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int n,m;
		scanf("%lld%lld",&n,&m);
		vector<pii> v1,v2;
		v1.pb(mp(0,1));
		v2.pb(mp(0,1));
		while(n--)
		{
			int x;
			scanf("%lld",&x);
			int cnt=1;
			while(x%m==0)
			{
				x/=m;
				cnt*=m;
			}
			if(x==v1.back().first)
				v1.back().second+=cnt;
			else	v1.pb(mp(x,cnt));
		}
		int k;
		scanf("%lld",&k);
		while(k--)
		{
			int x;
			scanf("%lld",&x);
			int cnt=1;
			while(x%m==0)
			{
				x/=m;
				cnt*=m;
			}
			if(x==v2.back().first)
				v2.back().second+=cnt;
			else	v2.pb(mp(x,cnt));
		}
		if(v1==v2)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}