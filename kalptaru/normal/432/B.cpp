#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ho[100001]={0},aw[n],h;
		FOR(i,0,n)
		{
			cin>>h>>aw[i];
			ho[h]++;
		}
		h=n-1;
		FOR(i,0,n)
		{
			cout<<(h+ho[aw[i]])<<' '<<(h-ho[aw[i]])<<"\n";
		}
	}
}