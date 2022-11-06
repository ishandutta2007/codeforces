#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		double x,y,a,b,ans=0;
		bool f=0;
		cin>>n>>x>>y;
		double d[n];
		FOR(i,0,n)
		{
			cin>>a>>b;
			if(b-y==0)d[i]=100000;
			else
			{
				d[i]=(a-x)/(b-y);
			}
		}	
		sort(d,d+n);
		double g=1000000;
		FOR(i,0,n)
		{
			if(d[i]!=g)
			{
				ans++;
				g=d[i];
			}
		}
		cout<<ans;
		
	}
}