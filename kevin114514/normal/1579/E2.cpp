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
int x[200200];
int n;
void discret()
{
	vector<int> v;
	for(int i=1;i<=n;i++)
		v.pb(x[i]);
	srt(v);
	for(int i=1;i<=n;i++)
		x[i]=lower_bound(ALL(v),x[i])-v.begin()+1;
}
int bit[400400];
void update(int p)
{
	while(p<=n)
	{
		bit[p]++;
		p+=(p&(-p));
	}
}
int query(int p)
{
	int ans=0;
	while(p)
	{
		ans+=bit[p];
		p-=(p&(-p));
	}
	return ans;
}
int cnt[400400];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<=n+200;i++)
			bit[i]=cnt[i]=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		discret();
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int x1=query(x[i]-1);
			int x2=i-1-x1-cnt[x[i]];
			cnt[x[i]]++;
			update(x[i]);
			ans+=min(x1,x2);
		}
		cout<<ans<<endl;
	}
	return 0;
}