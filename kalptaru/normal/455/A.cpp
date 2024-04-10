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
ll b2d(ll a)
{
	ll r=0,j=1;
	while(a>0)
	{
		if(a%2==1)
		r+=j;
		j*=10;
		a=a>>1;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,h;
		cin>>n;
		ll c[100001]={0};
		FOR(i,0,n)
		{
			cin>>h;
			c[h]++;
		}
		ll f2=0,f1=c[1],f0;
		FOR(i,2,100001)
		{
			f0=max(f1,f2+c[i]*i);
			f2=f1;
			f1=f0;
		}
		cout<<f0;
	}
}