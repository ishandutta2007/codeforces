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
#define longer __int128_t
longer s[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
			for(int j=1;j<=m;j++)
			{
				ll x;
				cin>>x;
				s[i]+=(longer)(j)*(x);
			}
		}
		longer mx=s[1],mn=s[1];
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			mn=min(mn,s[i]);
			if(s[i]>mx)
			{
				ans=i;
				mx=s[i];
			}
		}
		cout<<ans<<" "<<(ll)(mx-mn)<<endl;
	}
	return 0;
}