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
		ll a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[2]>2*(a[1]+a[0]))
		{
			cout<<a[1]+a[0];
		}
		else
		{
			cout<<(a[1]+a[2]+a[0])/3;
		}
	}
}