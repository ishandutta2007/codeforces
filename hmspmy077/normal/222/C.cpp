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

const int lim=10000005;

const int N=100005;

int a[N],b[N],f[lim],g1[lim],g2[lim],g3[lim];

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for (int i=2;i<=lim;i++) if (f[i]==0)
	{
		f[i]=i;
		for (int j=i+i;j<=lim;j+=i) f[j]=i;
	}
	for (int i=0;i<n;i++)
	{
		int j;
		cin>>a[i];
		j=a[i];
		while (j>1)
		{
			g1[f[j]]++;
			j/=f[j];
		}
	}
	for (int i=0;i<m;i++)
	{
		int j;
		cin>>b[i];
		j=b[i];
		while (j>1)
		{
			g2[f[j]]++;
			j/=f[j];
		}
	}
	for (int i=2;i<=lim;i++) g3[i]=min(g1[i],g2[i]);
	for (int i=0;i<n;i++)
	{
		int j=a[i];
		while (j>1)
		{
			if (g3[f[j]])
			{
				g3[f[j]]--;
				a[i]/=f[j];
			}
			j/=f[j];
		}
	}
	for (int i=2;i<=lim;i++) g3[i]=min(g1[i],g2[i]);
	for (int i=0;i<m;i++)
	{
		int j=b[i];
		while (j>1)
		{
			if (g3[f[j]])
			{
				g3[f[j]]--;
				b[i]/=f[j];
			}
			j/=f[j];
		}
	}
	cout<<n<<" "<<m<<endl;
	cout<<a[0]; for (int i=1;i<n;i++) cout<<" "<<a[i]; cout<<endl;
	cout<<b[0]; for (int i=1;i<m;i++) cout<<" "<<b[i]; cout<<endl;
	return 0;
}