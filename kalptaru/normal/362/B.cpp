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
		ll n,m;
		cin>>n>>m;
		readarr(d,m);
		sort(d,d+m);
		bool f=(d[0]!=1 && d[m-1]!=n);
		FOR(i,0,m-2)
		{
			if((d[i+2]-d[i+1])==1 && (d[i+1]-d[i])==1)
			{
				f=0;
				break;
			}
		}
		if(f)
		cout<<"YES";
		else
		cout<<"NO";
	}
}