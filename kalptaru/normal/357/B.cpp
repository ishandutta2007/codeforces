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
		int n,m,x,y,z;
		cin>>n>>m;
		bool p[n+1]={0};
		int c[n+1]={0};
		FOR(i,1,m+1)
		{
			cin>>x>>y>>z;
			if(p[x]==1)
			{
				p[y]=1;
				p[z]=1;
				c[y]=mod(c[x]);
				c[z]=mod(c[y]);
			}
			else if(p[y]==1)
			{
				p[x]=1;
				p[z]=1;
				c[x]=mod(c[y]);
				c[z]=mod(c[x]);	
			}
			else if(p[z]==1)
			{
				p[y]=1;
				p[x]=1;
				c[y]=mod(c[z]);
				c[x]=mod(c[y]);
			}
			else
			{
				p[x]=1;p[y]=1;p[z]=1;
				c[x]=1;c[y]=2;c[z]=3;
			}
		}
		printarr(c,1,n)
	}
}