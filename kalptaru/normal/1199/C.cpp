#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
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
		ll n,i;
		cin>>n>>i;
		readarr(a,n);
		ll g=i*8;
		g=g/n;
		if(g>log2(n))
		{
			cout<<0;
			return 0;
		}
		g=pow(2,g);
		sort(a,a+n);
		int v=a[0],l=0,r=0,m=0;
		ll p=a[0];
		FOR(i,0,n)
		{
			if(a[i]!=p)
			{
				p=a[i];
				a[i]=a[i-1]+1;
			}
			else if(i>0)
			{
				a[i]=a[i-1];
			}
		}
		while(r<n)
		{
			if(a[r]<v+g)
			{
				r++;
			}
			else
			{
				l++;
				v=a[l];
			}
			m=max(m,r-l);
		}
		cout<<n-m;	
	}
}