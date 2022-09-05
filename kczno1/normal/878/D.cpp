#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5,K=14;
int a[K][N],q[N][K];
bitset<1<<12>f[N+K];int tot;

int main()
{
//	freopen("1.in","r",stdin);
	int n,k,m;
	cin>>n>>k>>m;
	rep(i,0,k-1)
	rep(j,1,n)scanf("%d",&a[i][j]);
	rep(j,1,n)
	{
		rep(i,0,k-1)q[j][i]=i;
		sort(q[j],q[j]+k,[&](int x,int y) ->bool{ return a[x][j]<a[y][j]; });
	}
	int u=(1<<k)-1;
	rep(i,0,k-1)
	rep(j,0,u)
	if(j&(1<<i))f[i+1][j]=1;
	
	tot=k;
	while(m--)
	{
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type==3)
		{
			int i=0,s=u;
			while(i<k)
			{
				if(!f[x][s])break;
				s-=1<<q[y][i];
				++i;
			}
			printf("%d\n",a[q[y][i-1]][y]);
		}
		else
		{
			++tot;
			if(type==1)f[tot]=f[x]|f[y];
			else f[tot]=f[x]&f[y];
		}
	}
}