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

int a[105][105];
int p[105],q[105],f[105],g[105];

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) cin>>a[i][j],p[i]+=a[i][j],q[j]+=a[i][j];
	int a1=0,a2=0;
	while (1)
	{
		int ok=0;
		for (int i=0;i<n;i++) if (p[i]<0)
		{
			if (f[i]==0) a1++;
			else a1--;
			f[i]=1-f[i];
			p[i]=-p[i];
			for (int j=0;j<m;j++)
			{
				a[i][j]=-a[i][j];
				q[j]+=a[i][j]*2;
			}
			ok=1;
		}
		for (int j=0;j<m;j++) if (q[j]<0)
		{
			if (g[j]==0) a2++;
			else a2--;
			g[j]=1-g[j];
			q[j]=-q[j];
			for (int i=0;i<n;i++)
			{
				a[i][j]=-a[i][j];
				p[i]+=a[i][j]*2;
			}
			ok=1;
		}
		if (ok==0) break;
	}
	cout<<a1; for (int i=0;i<n;i++) if (f[i]) cout<<" "<<i+1; cout<<endl;
	cout<<a2; for (int i=0;i<m;i++) if (g[i]) cout<<" "<<i+1; cout<<endl;
	return 0;
}