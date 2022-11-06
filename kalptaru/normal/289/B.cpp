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
		int n,m,d,h,ans=0;
		cin>>n>>m>>d;
		readarr(a,n*m);
		int r=a[1]%d;
		FOR(i,1,n*m+1)
		{
			if(a[i]%d!=r)
			{
				cout<<-1;
				return 0;
			}
		}
		sort(a+1,a+n*m+1);
		h=a[n*m/2+1];
		FOR(i,1,n*m+1)
		{
			ans+=(abs(a[i]-h)/d);
		}
		cout<<ans;
	}
}