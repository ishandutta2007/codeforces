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
		ll mnx=0,mxx=0,mny=0,mxy=0;
		while(n--)
		{
			ll x,y;
			cin>>x>>y;
			if(!x)
			{
				mny=min(mny,y);
				mxy=max(mxy,y);
			}
			else
			{
				mnx=min(mnx,x);
				mxx=max(mxx,x);
			}
		}
		cout<<(mxx-mnx+mxy-mny)*2<<endl;
	}
	return 0;
}