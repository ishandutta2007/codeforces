#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=200005;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

struct query
{
	int u,d,id;
};

int n,p[MAXN],C[MAXN];
LL ans[MAXN];
vector <query> qu[2][MAXN];

void add(int x)
{
	for (;x<=n;x+=x&-x)
		C[x]++;
}

int sum(int x)
{
	int ret=0;
	for (;x;x-=x&-x)
		ret+=C[x];
	return ret;
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=0;i<m;i++)
	{
		int l,r,d,u;
		scanf("%d%d%d%d",&l,&d,&r,&u);
		ans[i]=n*(n-1LL)/2-(l-1)*(l-2LL)/2-(n-r)*(n-r-1LL)/2-(d-1)*(d-2LL)/2-(n-u)*(n-u-1LL)/2;
		qu[0][l-1].pb((query){u,d,i});
		qu[1][r+1].pb((query){u,d,i});
	}
	for (int i=1;i<=n;i++)
	{
		add(p[i]);
		for (int j=0;j<qu[0][i].size();j++)
		{
			int k=sum(qu[0][i][j].d-1);
			ans[qu[0][i][j].id]+=k*(k-1LL)/2;
			k=i-sum(qu[0][i][j].u);
			ans[qu[0][i][j].id]+=k*(k-1LL)/2;
		}
	}
	memset(C,0,sizeof(C));
	for (int i=n;i>=1;i--)
	{
		add(p[i]);
		for (int j=0;j<qu[1][i].size();j++)
		{
			int k=sum(qu[1][i][j].d-1);
			ans[qu[1][i][j].id]+=k*(k-1LL)/2;
			k=n-i+1-sum(qu[1][i][j].u);
			ans[qu[1][i][j].id]+=k*(k-1LL)/2;
		}
	}
	for (int i=0;i<m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}