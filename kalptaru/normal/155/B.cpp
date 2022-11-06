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
		int n,u,d;
		cin>>n;
		ll ans=0,c=1;
		vector <int> a;
		FOR(i,0,n)
		{
			cin>>u>>d;
			if(d==0)
			a.push_back(u);
			else
			{
				c+=d;
				c--;
				ans+=u;
			}
		}
		sort(a.begin(),a.end());
		u=a.size();
		FOR(i,0,u)
		{
			if(i<c)
			{
				ans+=a[u-i-1];
			}
			else
			break;
		}
		cout<<ans;
	}
}