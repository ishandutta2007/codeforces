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
int a[100100];
ll b[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		vector<ll> vec[2];
		for(int i=1;i<=n;i++)
			vec[a[i]].pb(b[i]);
		rsrt(vec[0]);
		rsrt(vec[1]);
		if(sz(vec[0])>sz(vec[1])) swap(vec[0],vec[1]);
		ll ans=0;
		for(int i=0;i<sz(vec[0]);i++)
			ans+=2*(vec[0][i]+vec[1][i]);
		for(int i=sz(vec[0]);i<sz(vec[1]);i++)
			ans+=vec[1][i];
		if(sz(vec[0])==sz(vec[1])) ans-=min(vec[0].back(),vec[1].back());
		cout<<ans<<endl;
	}
	return 0;
}