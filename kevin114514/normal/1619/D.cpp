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
int c[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
		for(int i=1;i<=n;i++)
			c[i]=0;
		int ans=0;
		while(m--)
		{
			vector<int> v;
			for(int i=1;i<=n;i++)
			{
				int x;
				cin>>x;
				v.pb(x);
				c[i]=max(c[i],x);
			}
			rsrt(v);
			ans=max(ans,v[1]);
		}
		cout<<min(*min_element(c+1,c+n+1),ans)<<endl;
	}
	return 0;
}