#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define mp make_pair
#define pii pair<int,int>
int n,m,N,M,i,j,k,u[MAXN],v[MAXN],d[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],w[MAXN<<1],ans[MAXN];
set<pii > s;
bool b[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&N);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",u+i,v+i);
		p[++M]=v[i];
		ne[M]=h[u[i]];
		w[M]=i;
		h[u[i]]=M;
		p[++M]=u[i];
		ne[M]=h[v[i]];
		w[M]=i;
		h[v[i]]=M;
		d[u[i]]++;
		d[v[i]]++;
	}
	for(i=1;i<=n;i++)s.insert(mp(d[i],i));
	for(i=m;i;i--)
	{
		for(;!s.empty()&&s.begin()->first<N;)
		{
			for(j=h[k=s.begin()->second];j;j=ne[j])if(!b[p[j]]&&w[j]<=i)
			{
				s.erase(s.find(mp(d[p[j]]--,p[j])));
				s.insert(mp(d[p[j]],p[j]));
			}
			b[k]=1;
			s.erase(s.find(mp(d[k],k)));
		}
		ans[i]=s.size();
		if(!b[u[i]]&&!b[v[i]])
		{
			s.erase(s.find(mp(d[u[i]]--,u[i])));
			s.insert(mp(d[u[i]],u[i]));
			s.erase(s.find(mp(d[v[i]]--,v[i])));
			s.insert(mp(d[v[i]],v[i]));
		}
	}
	for(i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}