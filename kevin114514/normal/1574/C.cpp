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
int main()
{
	int n;
	scanf("%d",&n);
	vector<ll> v;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		ll x;
		scanf("%I64d",&x);
		v.pb(x);
		sum+=x;
	}
	srt(v);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		int p=lower_bound(ALL(v),x)-v.begin();
		if(!p)
		{
			ll cur=sum-v[0];
			printf("%I64d\n",max(0ll,y-cur));
		}
		else if(p==n)
		{
			ll spend1=x-v[n-1];
			ll cur=sum-v[n-1];
			printf("%I64d\n",max(0ll,y-cur)+spend1);
		}
		else
		{
			ll cur1=sum-v[p];
			ll spend1=x-v[p-1];
			ll cur2=sum-v[p-1];
			printf("%I64d\n",min(max(0ll,y-cur1),max(0ll,y-cur2)+spend1));
		}
	}
	return 0;
}