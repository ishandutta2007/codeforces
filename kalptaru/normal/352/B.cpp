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
vector <int> p[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,s;
		cin>>n;
		readarr(a,n);
		FOR(i,1,n+1)
		p[a[i]].push_back(i);
		int ans[100000][2],y=0;
		FOR(i,1,100001)
		{
			s=p[i].size();
			if(s==1)
			{
				ans[y][0]=i;
				ans[y][1]=0;
				y++;
			}
			else if(s==2)
			{
				ans[y][0]=i;
				ans[y][1]=p[i][1]-p[i][0];
				y++;
			}
			else if(s>2)
			{
				bool f=1;
				int d=p[i][1]-p[i][0];
				FOR(j,2,s)
				{
					if(p[i][j]-p[i][j-1]!=d)
					{
						f=0;
						break;
					}
				}
				if(f)
				{
					ans[y][0]=i;
					ans[y][1]=d;
					y++;
				}
			}
		}
		cout<<y<<"\n";
		FOR(i,0,y)
		{
			cout<<ans[i][0]<<' '<<ans[i][1]<<"\n";
		}
	}
}