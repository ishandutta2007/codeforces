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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,r,c;
		cin>>n>>m>>r>>c;
		int ans=3;
		c--;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<m;j++) if(s[j]=='B')
				ans=min(ans,2-(i==r)-(j==c));
		}
		if(ans==3)
			ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}