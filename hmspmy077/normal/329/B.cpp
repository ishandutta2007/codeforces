#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

typedef long long int64;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define ms(a,x)

const int N=1005;
int P[]={-1,1,0,0};
int Q[]={0,0,1,-1};

int v[N][N],f[N][N];
char a[N][N];
queue<pair<int,int> > QQ;

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y;
	int p,q;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf(" %c",&a[i][j]);
			v[i][j]=1;
			f[i][j]=1000000000;
			if (a[i][j]=='E')
			{
				x=i;
				y=j;
			}
			if (a[i][j]=='S')
			{
				p=i;
				q=j;
			}
		}
	f[x][y]=0;
	QQ.push(mp(x,y));
	while (!QQ.empty())
	{
		x=QQ.front().first;
		y=QQ.front().second;
		QQ.pop();
		for (int k=0;k<4;++k)
		{
			int xx=x+P[k];
			int yy=y+Q[k];
			if (!v[xx][yy]) continue;
			if (a[xx][yy]=='T') continue;
			if (f[xx][yy]!=1000000000) continue;
			f[xx][yy]=f[x][y]+1;
			QQ.push(mp(xx,yy));
		}
	}
	int ans=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (f[i][j]<=f[p][q] && isdigit(a[i][j]))
				ans+=a[i][j]-'0';
	cout<<ans<<endl;
	return 0;
}