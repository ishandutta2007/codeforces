#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7;

pair<int,int> a[maxn];
int dp[maxn];

bool can(int i,int m)
{
	return a[m].f < a[i].f - a[i].s;
}
int main()
{
	int n;
	scanf("%d",&n);

	for (int i=0;i<n;i++){
		scanf("%d %d",&a[i].f,&a[i].s);
	}
	sort(a,a+n);
	dp[0] = 1;

	for (int i=1;i<n;i++){
		int l = 0 , r = i-1;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (can(i,m))
				l = m;
			else
				r = m;
		}
		if (!can(i,l))
			l = -1;
		if (can(i,r))
			l = r;
		if ( l == -1 )
			dp[i] = 1;
		else
			dp[i] = 1 + dp[l];
	}
	int ans = 0;
	for (int i=0;i<n;i++)
		ans = max(ans,dp[i]);
	cout<<n - ans;
	return 0;
}