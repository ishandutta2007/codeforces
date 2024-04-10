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
int a[100100];
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
		for(int i=1;i<=m;i++)
			cin>>a[i];
		sort(a+1,a+m+1);
		multiset<int> st0,st1;
		for(int i=1;i<m;i++) if(a[i+1]!=a[i]+1)
			st0.insert(a[i+1]-a[i]-1);
		if(a[1]!=1||a[m]!=n)
			st0.insert(a[1]+n-a[m]-1);
		int ans=0;
		int day=0;
		while(sz(st0)||sz(st1))
		{
			if(sz(st1))
			{
				auto it=st1.end();
				it--;
				ans+=*it-day;
				st1.erase(it);
			}
			else
			{
				auto it=st0.end();
				it--;
				int x=*it;
				st0.erase(it);
				st1.insert(x-day-1);
				ans++;
			}
			day++;
			while(sz(st0)&&*st0.begin()<=day+day)
				st0.erase(st0.begin());
			while(sz(st1)&&*st1.begin()<=day)
				st1.erase(st1.begin());
		}
		cout<<n-ans<<endl;
	}
	return 0;
}