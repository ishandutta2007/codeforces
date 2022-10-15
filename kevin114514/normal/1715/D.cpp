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
vector<pii> vec[100100];
int ans[100100];
bool f[100100];
int xx[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		xx[i]=(1<<30)-1;
	while(q--)
	{
		int i,j,x;
		cin>>i>>j>>x;
		if(i>j)
			swap(i,j);
		vec[i].pb(mp(j,x));
		xx[i]&=x;
		xx[j]&=x;
	}
	for(int i=1;i<=n;i++)
	{
		for(auto p:vec[i])
			if(i!=p.first)
				ans[i]|=(p.second-xx[p.first]);
			else	ans[i]|=p.second;
		for(auto p:vec[i])
			ans[p.first]|=(p.second-ans[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}