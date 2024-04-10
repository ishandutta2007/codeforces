#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=3e4+100,M=210;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
void go() { puts("-1"); exit(0); }
int d[M][N],id[N];
int p[M][N],pre[N];
bool in[N];
int C;

int fa[N];
vector<int>e[N];
inline int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
vector<pair<int,int> >sub[N];
inline void link(int a,int b) {
	e[a].push_back(b);
	e[b].push_back(a);
}


int main(){
	int n=gi(),m=gi(),i,j,k,last,ld,t,mx,to;
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++) {
		for (j=1;j<=n;j++)
			if (!(d[i][j]=gi()))
				id[i]=j;
		if (!id[i]) go();
	}
	p[1][0]=id[1];in[id[1]]=true;
	for (k=2;k<=m;k++) {
		for (i=1;i<=n;i++)
			if (d[1][i]+d[k][i]==d[1][id[k]])
				p[k][d[1][i]]=i,in[i]=true;
		for (i=d[1][id[k]];i;i--) {
			if (!p[k][i]) go();
			pre[p[k][i]]=p[k][i-1];
		}
	}
	for (k=1;k<=n;k++)
		if (!in[k]) {
			mx=-1;
			for (i=1;i<=m;i++) {
				t=(d[1][id[i]]+d[1][k]-d[i][k])/2;
				if (t>mx) mx=t,to=p[i][t];
			}
			sub[to].push_back(make_pair(d[1][k],k));
		}
	for (k=1;k<=n;k++) {
		sort(sub[k].begin(),sub[k].end());
		for (i=0,last=k,ld=d[1][k];i<sub[k].size();i++) {
			if (i&&sub[k][i].first!=sub[k][i-1].first)
				ld=d[1][last=sub[k][i-1].second];
			if (sub[k][i].first!=ld+1) go();
			pre[sub[k][i].second]=last;
		}
	}
	for (i=1;i<=n;i++) if (pre[i]) printf("%d %d\n",pre[i],i);
	
	return 0;
}