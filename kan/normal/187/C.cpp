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

const int maxn=100005;
const int inf=1e9;

vector <int> gr[maxn];
int d[maxn];
int mark[maxn];
int o[maxn];
int id[maxn];
int n,m,k,S,T;

bool can(int q)
{
	for (int i=0;i<n;i++) d[i]=inf;
	d[S]=0;
	memset(id,0,sizeof(id));
	int bo=0;
	int eo=0;
	o[eo]=S;
	id[S]=1;
	int ko=1;
	eo++;
	while (ko>0)
	{
		int cur=o[bo];
		bo++;
		if (bo==n) bo=0;
		ko--;
		id[cur]=0;
		if (mark[cur]) d[cur]=0;
		if (d[cur]==q) continue;
		for (int i=0;i<gr[cur].size();i++)
		{
// 			cout << cur << ' ' << i << endl;
			int next=gr[cur][i];
			if (d[next]>d[cur]+1)
			{
				d[next]=d[cur]+1;
				if (id[next]==0)
				{
					o[eo]=next;
					eo++;
					if (eo==n) eo=0;
					ko++;
					id[next]=1;
				}
			}
		}
	}
// 	cout << "can " << q << endl;
// 	for (int i=0;i<n;i++) cout << d[i] << endl;
	return (d[T]!=inf);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(mark,0,sizeof(mark));
	for (int i=0;i<k;i++)
	{
		int T;
		scanf("%d",&T);
		T--;
		mark[T]=1;
	}
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	scanf("%d%d",&S,&T);
	S--,T--;
	int l=0;
	int r=n;
	while (r-l>1)
	{
		int m=(l+r)/2;
		if (can(m)) r=m;
		else l=m;
	}
	if (!can(r))
	{
		r=-1;
	}
	cout << r << endl;
	return 0;
}