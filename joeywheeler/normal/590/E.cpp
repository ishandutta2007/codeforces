#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

const int MAXN = 1e7+10, sigma = 2;

int term[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;
int que[MAXN], ww[MAXN];

namespace MF {
	const int N = 755*2, M = 755*755;
	int f[N], e[2*M], c[2*M], fl[2*M], nxt[2*M], ce;
	int n, s, t;
	int Q[N], lvl[N];
	int le[N];

	void init(int _n) {
		n = _n+2; s = _n; t = _n+1; ce = 0;
		FO(i,0,n) f[i]=-1;
	}

	void add(int a, int b, int cap) {
		nxt[ce]=f[a]; f[a]=ce; e[ce]=b; fl[ce]=0; c[ce]=cap; ce++;
		nxt[ce]=f[b]; f[b]=ce; e[ce]=a; fl[ce]=0; c[ce]=0; ce++;
	}

	bool bfs() {
		FO(i,0,n) lvl[i]=-1;
		int qi = 1;
		Q[0] = s; lvl[s] = 0;
		FO(i,0,qi) {
			int x=Q[i];
			le[x]=f[x];
			for (int j=f[x];j>=0;j=nxt[j]) if (c[j]-fl[j]>0) {
				int y=e[j];
				if (lvl[y]==-1) {
					lvl[y]=lvl[x]+1;
					Q[qi++]=y;
				}
			}
		}
		return lvl[t]!=-1;
	}

	int aug(int cu, int cf) {
		if (cu == t) return cf;
		for (int &i=le[cu];i>=0;i=nxt[i]) if (c[i]-fl[i]>0) {
			int x=e[i];
			if (lvl[x]!=lvl[cu]+1) continue;
			int rf = aug(x,min(cf,c[i]-fl[i]));
			if (rf>0) {
				fl[i]+=rf;
				fl[i^1]-=rf;
				return rf;
			}
		}
		lvl[cu]=-1;
		return 0;
	}

	int mf() {
		int tot = 0;
		while (bfs())
			for (int x=aug(s,1e9);x;x=aug(s,1e9)) tot+=x;
		return tot;
	}
}


void add_str(string &s, int i) {
	int cur = 0;
	for(auto c: s)
	{
		if(!to[cur][c - 'a']) {
			to[cur][c - 'a'] = sz++;
		}
		cur = to[cur][c - 'a'];
	}
	term[cur] = cur; 
	ww[cur] = i;
}

int u[755][755];
int mt[755][755];
int ei[755][755];
bool inz[2][755];

void calc_str(string &s, int i) {
	int cur = 0;
	for(auto c: s) {
		cur = to[cur][c - 'a'];
		for (int sl = term[cur]; sl; sl = term[link[sl]]) {
			if (u[i][ww[sl]]) break;
			u[i][ww[sl]] = true;
		}
	}
}

void push_links()
{
	int st = 0, fi = 1;
	que[0] = 0;
	while(st < fi)
	{
		int V = que[st++];
		int U = link[V];
		//printf("link[%d]=%d\n", V, U);
		if(!term[V]) term[V] = term[U];
		for(int c = 0; c < sigma; c++)
			if(to[V][c])
			{
				link[to[V][c]] = V ? to[U][c] : 0;
				que[fi++] = to[V][c];
			}
			else
			{
				to[V][c] = to[U][c];
			}
	}
}

int n;
vector<string> v;

void go(int s, int i) {
	if (inz[s][i]) return;
	inz[s][i] = true;
	//printf("(%d,%d)\n", s, i);
	FO(j,0,n) {
		if (s == 0) {
			if (u[i][j] && !mt[i][j]) go(1,j);
		} else {
			if (u[j][i] && mt[j][i]) go(0,j);
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;
	v.resize(n);
	FO(i,0,n) {
		cin >> v[i];
		add_str(v[i],i);
	}
	push_links();
	FO(i,0,n) {
		calc_str(v[i],i);
	}
	FO(i,0,n) {
		u[i][i] = false;
		FO(j,0,n) if (u[i][j]) {
			//printf("%s -> %s\n", v[j].c_str(), v[i].c_str());
			//printf("%d -- %d\n", i, j);
		}
	}
	MF::init(2*n);
	FO(i,0,n) {
		MF::add(MF::s, i, 1);
		MF::add(n+i, MF::t, 1);
	}
	FO(i,0,n) FO(j,0,n) if (u[i][j]) {
		ei[i][j] = MF::ce;
		MF::add(i, j+n, 1);
	}
	int flo = MF::mf();
	printf("%d\n", n-flo);
	FO(i,0,n) FO(j,0,n) if (u[i][j] && MF::fl[ei[i][j]]) {
		mt[i][j] = 1;
		//printf("%d-%d\n", i, j);
	}
	FO(i,0,n) {
		bool unm = true;
		FO(j,0,n) if (mt[i][j]) {
			unm = false;
		}
		if (unm) go(0,i);
	}
	vector<int> res;
	FO(i,0,n) if (inz[0][i] && !inz[1][i]) res.push_back(i);
	assert(n-flo == sz(res));
	for (int x : res) printf("%d ", x+1);
	printf("\n");
}