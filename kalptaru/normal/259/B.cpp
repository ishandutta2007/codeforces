#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		readmat(a,3,3);
		a[1][1]-=(a[0][1]+a[2][1]-a[1][0]-a[2][0]);
		a[2][2]-=(a[0][2]+a[1][2]-a[1][0]-a[2][0]);
		t=(-a[1][1]-a[2][2]+a[1][0]+a[2][0])>>1;
		FOR(i,0,3)
		a[i][i]+=t;
		t=0;
		printmat(a,3,3);
	}
}