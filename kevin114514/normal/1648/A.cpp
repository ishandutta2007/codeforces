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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> r[100100],c[100100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			r[x].pb(i);
			c[x].pb(j);
		}
	ll ans=0;
	for(int i=1;i<=100000;i++)
	{
		srt(r[i]);
		for(int j=0;j<sz(r[i])-1;j++)
			ans+=1ll*(r[i][j+1]-r[i][j])*(j+1)*(sz(r[i])-j-1);
		r[i]=c[i];
		srt(r[i]);
		for(int j=0;j<sz(r[i])-1;j++)
			ans+=1ll*(r[i][j+1]-r[i][j])*(j+1)*(sz(r[i])-j-1);
	}
	cout<<ans<<endl;
	return 0;
}