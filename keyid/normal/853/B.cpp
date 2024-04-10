#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=100005,MAXD=1000005;
const LL INF=1000000000000LL;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

vector <pii> fli[2][MAXN];
int head[MAXN];
LL c1[MAXD],c2[MAXD],mn[MAXN];
priority_queue <pii> q;

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while (m--)
	{
		int d,f,t,c;
		scanf("%d%d%d%d",&d,&f,&t,&c);
		if (t==0)
			fli[0][f].pb(mp(d,c));
		else
			fli[1][t].pb(mp(d,c));
	}
	for (int i=1;i<=n;i++)
		sort(fli[0][i].begin(),fli[0][i].end());
	for (int i=1;i<=n;i++)
		sort(fli[1][i].begin(),fli[1][i].end(),greater<pii>());
	LL now=INF*n;
	for (int i=1;i<=n;i++)
		mn[i]=INF;
	for (int i=1;i<=n;i++)
		if (!fli[0][i].empty())
			q.push(mp(-fli[0][i][0].fi,i));
	for (int i=1;i<=1000000;i++)
	{
		while (!q.empty()&&-q.top().fi<=i)
		{
			int x=q.top().sc;
			q.pop();
			now-=mn[x];
			mn[x]=min(mn[x],(LL)fli[0][x][head[x]].sc);
			now+=mn[x];
			head[x]++;
			if (head[x]<fli[0][x].size())
				q.push(mp(-fli[0][x][head[x]].fi,x));
		}
		c1[i]=now;
	}
	now=INF*n;
	for (int i=1;i<=n;i++)
		mn[i]=INF;
	memset(head,0,sizeof(head));
	while (!q.empty())
		q.pop();
	for (int i=1;i<=n;i++)
		if (!fli[1][i].empty())
			q.push(mp(fli[1][i][0].fi,i));
	for (int i=1000000;i>=1;i--)
	{
		while (!q.empty()&&q.top().fi>=i)
		{
			int x=q.top().sc;
			q.pop();
			now-=mn[x];
			mn[x]=min(mn[x],(LL)fli[1][x][head[x]].sc);
			now+=mn[x];
			head[x]++;
			if (head[x]<fli[1][x].size())
				q.push(mp(fli[1][x][head[x]].fi,x));
		}
		c2[i]=now;
	}
	LL ans=LLONG_MAX;
	for (int i=1;i+k<1000000;i++)
		ans=min(ans,c1[i]+c2[i+k+1]);
	printf("%lld",ans<INF?ans:-1);
	return 0;
}