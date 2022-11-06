#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
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
		ll a[n][n];
		ll d1[2*n-1]={0},d2[2*n-1]={0};
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				cin>>a[i][j];
				d1[i+j]+=a[i][j];
				d2[j-i+n-1]+=a[i][j];
			}
		}
		ll w=0,b=0,c;
		int bi=1,bj=1,wi=1,wj=2;
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				c=d1[i+j]+d2[j-i+n-1]-a[i][j];
				if((i+j)%2==0)
				{
					if(c>b)
					{
						bi=i;
						bj=j;
						b=c;
					}
				}
				else
				{
					if(c>w)
					{
						wi=i;
						wj=j;
						w=c;
					}
				}
			}
		}
		cout<<b+w<<"\n";
		cout<<wi+1<<' '<<wj+1<<' '<<bi+1<<' '<<bj+1;
		
	}
}