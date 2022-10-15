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
		int n,k;
		cin>>n>>k;
		vector<ll> vec;
		for(int i=0;i<k;i++)
		{
			ll x;
			cin>>x;
			vec.pb(x);
		}
		if(k==1)
			puts("Yes");
		else
		{
			ll f=vec[1]-vec[0];
			if(f*(n-k+1)<vec[0])
				puts("No");
			else
			{
				bool fl=1;
				for(int i=2;i<sz(vec);i++)
					if(vec[i]-vec[i-1]<f)
					{
						fl=0;
						break;
					}
					else	f=vec[i]-vec[i-1];
				if(fl)
					puts("Yes");
				else	puts("No");
			}
		}
	}
	return 0;
}