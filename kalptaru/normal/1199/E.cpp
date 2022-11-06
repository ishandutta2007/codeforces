#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
struct g
{
	int t;
	int p;
	int x;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin>>t;
	while(t--)
	{
		int n,m,u,v,j=0;
		cin>>n>>m;
		bool c[3*n+1]={0},e[m+1]={0},f=1;
		FOR(i,0,m)
		{
			cin>>u>>v;
			if(!(c[u] || c[v]))
			{
				c[u]=1;
				c[v]=1;
				e[i+1]=1;
				j++;
			}
			if(j==n && f==1)
			{
				cout<<"Matching\n";
				FOR(y,0,m+1)
				{
					if(e[y]==1)
					cout<<y<<' ';
				}
				f=0;
			}
		}
		if(f)
		{
			cout<<"IndSet\n";
			for(int i=0,j=1;i<n;j++)
			{
				if(c[j]==0)
				{
					cout<<j<<' ';
					i++;
				}
			}
		}
		cout<<"\n";
	}
}