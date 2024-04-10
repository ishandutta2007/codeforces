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

long long f[7][11][100005];
int p[100005][10],q[100005][10],n;

int low(int i)
{
	return i&(-i);
}

void up(int i,int j,int k,long long w)
{
	while (k<=n)
	{
		f[i][j][k]+=w;
		k+=low(k);
	}
}

long long ask(int i,int j,int k)
{
	long long t=0;
	while (k>0)
	{
		t+=f[i][j][k];
		k-=low(k);
	}
	return t;
}

long long cal(int i,int z)
{
	if (i%(z+z-2)==0) return 2;
	if (i%(z+z-2)<=z) return i%(z+z-2);
	return z+z-(i%(z+z-2));
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("d.in","r",stdin);
		freopen("d.out","w",stdout);
	#endif
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		for (int j=2;j<=6;j++)
		{
			int tot=(j-1)*2;
			p[i][j]=(i-1)%tot;
			q[i][j]=(i-1)/tot+1;
			up(j,p[i][j],q[i][j],tmp);
		}
	}
	int m; cin>>m;
	while (m--)
	{
		int t1,t2,t3,t4;
		cin>>t1>>t2>>t3;
		if (t1==1)
		{
			for (int i=2;i<=6;i++)
			{
				int pp=p[t2][i];
				int qq=q[t2][i];
				long long ff=ask(i,pp,qq)-ask(i,pp,qq-1);
				up(i,pp,qq,t3-ff);
			}
		}
		else
		{
			cin>>t4;
			int tot=(t4-1)*2;
			int fuck=p[t2][t4],count=1;
			long long ans=0;
			for (int i=fuck;;)
			{
				int l=t2;
				int r=t3;
				while (l<=t3 && (l-1)%tot!=i) l++;
				while (r>=t2 && (r-1)%tot!=i) r--;
				if (l<=r)
				{
					ans+=cal(count,t4)*(ask(t4,i,q[r][t4])-ask(t4,i,q[l][t4]-1));
				}
				i=(i+1)%tot;
				count++;
				if (i==fuck) break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}