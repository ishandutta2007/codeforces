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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		ll n,k,mi=101,ma=0;
		cin>>n>>k;
		readarr(a,n);
		FOR(i,0,n)
		{
			mi=min(mi,a[i]);
			ma=max(ma,a[i]);
		}
		if(ma-mi>k)
		{
			cout<<"NO";
			return 0;
		}
		else
		{
			cout<<"YES\n";
			FOR(i,0,n)
			{
				FOR(j,0,a[i])
				{
					if(j<mi)
					{
						cout<<(j)%k+1<<' ';
					}
					else
					{
						cout<<j-mi+1<<' ';
					}
				}
				cout<<"\n";
			}
		}
	}
}