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
ll a[1010][1010],x[1010][1010];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				x[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			x[1][i]=(1ll<<60)-1;
		for(int i=1;i<n;i++)
			for(int j=1;j<=n;j++)
				x[i+1][j]=a[i][j]^x[i-1][j]^x[i][j-1]^x[i][j+1];
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans^=x[i][j];
		cout<<ans<<endl;
	}
	return 0;
}