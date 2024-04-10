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
		int n,m;
		cin>>m>>n;
		readmat(a,m,n);
		bool r[m]={0},c[n]={0},f=1;
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				if(a[i][j]==0)
				{
					r[i]=1;
					c[j]=1;
				}
			}
		}
		FOR(i,0,m)
		{
			f=0;
			if(r[i]==0)break;
			f=1;
		}
		if(f)
		{
			FOR(i,0,n)
			c[i]=1;
		}
		else
		{
			FOR(i,0,n)
			{
				f=0;
				if(c[i]==0)break;
				f=1;
			}
			if(f)
			{
				FOR(i,0,m)
				r[i]=1;
			}
		}
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				if(r[i]==1 && c[j]==1)
				{
					if(a[i][j]==1)
					{	
						cout<<"NO";
						return 0;
					}
				}
				else if(r[i]==1 || c[j]==1)
				{
					a[i][j]=0;
				}
				else
				{
					a[i][j]=1;
				}
			}
		}
		cout<<"YES\n";
		printmat(a,m,n);
	}
}