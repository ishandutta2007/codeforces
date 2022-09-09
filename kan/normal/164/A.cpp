#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn=1e5+5;

int was1[maxn],was2[maxn],o[maxn],f[maxn];
vector <int> grt[maxn],grf[maxn];
int n,m;

int main()
{
	memset(was1,0,sizeof(was1));
	memset(was2,0,sizeof(was2));
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&f[i]);
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		grt[a].push_back(b);
		grf[b].push_back(a);
	}
	int eo=0;
	for (int i=0;i<n;i++)
	{
		if (f[i]==1)
		{
			o[eo]=i;
			was1[i]=1;
			eo++;
		}
	}
	int bo=0;
	while (bo<eo)
	{
		int cur=o[bo];
// 		cout << cur << endl;
		bo++;
		for (int i=0;i<grt[cur].size();i++)
		{
			int next=grt[cur][i];
// 			cout << next << endl;
			if (was1[next]==0 && f[next]!=1)
			{
				o[eo]=next;
				eo++;
			}
			if (was1[next]==0) was1[next]=1;
		}
	}
// 	cout << "first" << endl;
	eo=0;
	for (int i=0;i<n;i++)
	{
		if (f[i]==2)
		{
			o[eo]=i;
			was2[i]=1;
			eo++;
		}
	}
	bo=0;
	while (bo<eo)
	{
		int cur=o[bo];
// 		cout << cur << endl;
		bo++;
		for (int i=0;i<grf[cur].size();i++)
		{
// 			cout << i << endl;
			int next=grf[cur][i];
			if (was2[next]==0 && f[next]!=1)
			{
				o[eo]=next;
				eo++;
			}
			if (was2[next]==0) was2[next]=1;
		}
	}
// 	for (int i=0;i<n;i++) cout << was1[i] << ' ' << was2[i] << endl;
	for (int i=0;i<n;i++) printf("%d\n",(was1[i]==1 && was2[i]==1) ? 1 : 0);
	return 0;
}