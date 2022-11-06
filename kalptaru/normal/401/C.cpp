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
		int n,m;
		cin>>n>>m;
		if(m>2*n+2 || m<n-1)
		cout<<-1;
		else
		{
			while(m>n && n>0)
			{
				cout<<110;
				m-=2;
				n--;
			}
			if(n==0)
			{FOR(i,0,m)cout<<1;}
			else if(m==n-1)
			{
				cout<<0;
				n--;
			}
			FOR(i,0,n)
			cout<<10;
			
		}
	}
}