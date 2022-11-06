#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(n) push_back((n));
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int v;
		cin>>v;
		readarr(a,9)
		int m=100001,mi;
		int p=9;
		FOR(i,1,10)
		{
			if(a[i]<m)
			{
				m=a[i];
				mi=i;
			}
		}
		if(m>v)
		{
			cout<<-1;
			return 0;
		}
		int ans[v/m];
		int l=v/m;
		FOR(i,0,v/m)
		ans[i]=mi;
		int j=v/m-1,k=j;
		v-=(j+1)*m;
		while(j>=0 && p>0)
		{
			if(v>=a[p]-m)
			{
				ans[j]=p;
				j--;
				v-=(a[p]-m);
			}
			else
			{
				p--;
			}
		}	
		FOR(i,1,l+1)
		cout<<ans[l-i];
		
	}
}