#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,m,g;
		int ans=0;
		cin>>n>>m;
		bool p[n+1]={0};
		p[0]=1;
		FOR(i,0,2*m)
		{
			cin>>g;
			p[g]=1;
		}
		FOR(i,1,n+1)
		{
			if(p[i]==0)
			{ans=i;break;}		
		}
		cout<<n-1<<"\n";
		FOR(i,1,n+1)
		{
			if(i==ans)continue;
			cout<<i<<' '<<ans<<"\n";
		}
	}
}