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
		ll k,b,s;
		cin>>n>>k>>b>>s;
		if(k*b>s)
			cout<<-1<<'\n';
		else if(k*b+n*(k-1)<s)
			cout<<-1<<'\n';
		else
		{
			ll sum=s-k*b;
			for(int i=0;i<n;i++)
			{
				ll x=min(sum,k-1);
				sum-=x%k;
				if(i==0)
					x+=k*b;
				cout<<x<<" ";
			}
			cout<<'\n';
		}
	}
	return 0;
}