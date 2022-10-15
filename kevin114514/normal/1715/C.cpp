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
int a[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	ll sum=1ll*n*(n+1)/2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]!=a[i+1])
			sum+=1ll*i*(n-i);
	while(m--)
	{
		int p,x;
		cin>>p>>x;
		if(a[p-1]!=a[p])
			sum-=1ll*(p-1)*(n-p+1);
		if(a[p]!=a[p+1])
			sum-=1ll*p*(n-p);
		a[p]=x;
		if(a[p-1]!=a[p])
			sum+=1ll*(p-1)*(n-p+1);
		if(a[p]!=a[p+1])
			sum+=1ll*p*(n-p);
		cout<<sum<<'\n';
	}
	return 0;
}