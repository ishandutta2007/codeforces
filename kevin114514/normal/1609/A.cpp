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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<ll> v;
		while(n--)
		{
			ll x;
			cin>>x;
			v.pb(x);
		}
		int cnt=0;
		for(auto &x:v)
			while(x%2==0)
			{
				x/=2;
				cnt++;
			}
		rsrt(v);
		v[0]*=(1ll<<cnt);
		ll sum=0;
		for(auto x:v)
		{
			sum+=x;
//			cout<<x<<endl;
		}
		cout<<sum<<endl;
	}
	return 0;
}