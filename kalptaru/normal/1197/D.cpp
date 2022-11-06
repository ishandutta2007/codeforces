#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
struct ele
{
	ll s=0,ma;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,m;
		ll v,k,ans=0;
		cin>>n>>m>>k;
		ll mi[m]={0};
		readarr(a,n);
		ele e[n/m+3][m],f;
		FOR(i,0,n)
		{
			f.s=0;
			f.ma=0;
			for(int j=0;i+j<n && j<m;j++)
			{
				v=f.s+a[i+j];
				f.ma=max(f.ma,v);
				f.s=v;
			}
			f.s-=k;
			f.ma-=k;
			e[i/m+1][i%m]=f;
		}
		FOR(i,0,n)
		{
			e[i/m+1][i%m].s+=e[i/m][i%m].s;
			ans=max(ans,(e[i/m+1][i%m].ma+e[i/m][i%m].s-mi[i%m]));
			mi[i%m]=min(mi[i%m],e[i/m+1][i%m].s);
		}
/*		FOR(i,0,n)
		{
			cout<<e[i/m+1][i%m].ma<<' ';
		}
*/		cout<<ans;
	}
}