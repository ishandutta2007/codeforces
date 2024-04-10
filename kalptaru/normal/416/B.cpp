#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]={0}; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int mod(int n)
{
	if(n==3)return 1;
	return n+1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
		ll d[(n+2)][(m+2)]={0};
		readmat(a,m,n);
		FOR(i,1,m+1)
		d[0][i]=0;
		FOR(j,1,m+1)
		{
			FOR(i,1,n+1)
			{
				d[i][j]=a[j][i]+max(d[i-1][j],d[i][j-1]);
			}
			cout<<d[n][j]<<' ';
		}
	}
}