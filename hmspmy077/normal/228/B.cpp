#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int a[105][105],b[105][105];

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	int n,m,p,q;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	cin>>p>>q;
	for (int i=1;i<=p;i++)
		for (int j=1;j<=q;j++)
		{
			char c;
			cin>>c;
			b[i][j]=c-'0';
		}
	int ans=-123456789,xx,yy;
	for (int x=-52;x<=52;x++)
		for (int y=-52;y<=52;y++)
		{
			int t=0;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=m;j++)
				{
					int ii=i+x;
					int jj=j+y;
					if (ii>=1 && ii<=p && jj>=1 && jj<=q) t+=a[i][j]*b[ii][jj];
				}
			if (t>ans)
			{
				ans=t;
				xx=x;
				yy=y;
			}
		}
	cout<<xx<<" "<<yy<<endl;
	return 0;
}