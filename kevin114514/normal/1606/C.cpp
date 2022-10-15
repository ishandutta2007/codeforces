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
void die(string S){puts(S.c_str());exit(0);}
ll pw10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		ll k;
		scanf("%d%lld",&n,&k);
		vector<ll> v;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			v.pb(pw10[x]);
		}
		k++;
		ll ans=0;
		v.pb(1e18);
		for(int i=1;i<=n;i++)
		{
			ll x=min(k,v[i]/v[i-1]-1);
			ans+=v[i-1]*x;
			k-=x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}