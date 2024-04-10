#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long long int llint;

const int MAXN=100005;

llint mod=1000000007;
int n, m, x, y, cnt, root, q;
int bio[MAXN];
int l[2*MAXN];
int rod[MAXN];
int dub[MAXN];
int sum[MAXN];
int parr[MAXN] [18];
vector <int> v[MAXN];
vector <int> g[MAXN];
vector <int> ucik;
vector <int> sus;
vector <int> tree;

void cik (int cvor) {
	sus.clear();
	ucik.clear();
	int st=cvor;
	while (1) {
		ucik.push_back(cvor);
		l[cvor]=-1;
		cvor=rod[cvor];
		if (cvor==st) break;
	}
	for (int i=0; i<ucik.size(); i++) {
		for (int j=0; j<v[ucik[i]].size(); j++) {
			if (l[v[ucik[i]] [j]]!=-1) {
				sus.push_back(v[ucik[i]] [j]);
			}
		}
	}
	st=cvor;
	while (1) {
		l[cvor]=cnt;
		cvor=rod[cvor];
		if (cvor==st) break;
	}
}

void dfs (int cvor, int par) {
	rod[cvor]=par;
	bio[cvor]=1;
	for (int i=0; i<v[cvor].size(); i++) {
		if (v[cvor] [i]!=par) {
			if (bio[v[cvor] [i]]==0) {
				dfs(v[cvor] [i], cvor);
			} else if (bio[v[cvor] [i]]==1) {
				rod[v[cvor] [i]]=cvor;
				cik(cvor);
				for (int j=0; j<sus.size(); j++) {
					g[cnt].push_back(sus[j]);
				}
				cnt++;
			}
		}
	}
	bio[cvor]=2;
}

void mp (int cvor, int par, int dep) {
	if (cvor>n) sum[cvor]=sum[par]+1; else sum[cvor]=sum[par];
	dub[cvor]=dep;
	parr[cvor] [0]=par;
	for (int i=0; i<g[cvor].size(); i++) {
		if (g[cvor] [i]!=par) mp(g[cvor] [i], cvor, dep+1);
	}
}

int digni (int cvor, int d) {
	int pot=0;
	while (d) {
		if (d%2) cvor=parr[cvor] [pot];
		d/=2;
		pot++;
	}
	return cvor;
}

int lca (int a, int b) {
	if (dub[a]<dub[b]) swap(a, b);
	a=digni(a, dub[a]-dub[b]);
	if (a==b) return a;
	for (int i=16; i>=0; i--) {
		if (parr[a] [i]!=parr[b] [i]) {
			a=parr[a] [i];
			b=parr[b] [i];
		}
	}
	return parr[a] [0];
}

llint po (llint val, llint e) {
	if (e==0) return 1;
	if (e%2==0) {
		llint bla=po(val, e/2);
		return (bla*bla)%mod;
	} else {
		llint bla=po(val, e-1);
		return (bla*val)%mod;
	}
}

bool is (char cc) {
	return '0'<=cc && cc<='9';
}
 
int read () {
	char cc='a';
	while (!is(cc)) cc=getchar();
	int res=0;
	res=cc-'0';
	while (1) {
		cc=getchar();
		if (!is(cc)) break;
		res=res*10+(cc-'0');
	}
	return res;
}

int main () {
	n=read();
	m=read();
	cnt=n+1;
	for (int i=0; i<m; i++) {
		x=read();
		y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	for (int i=1; i<cnt; i++) {
		if (cnt>n) {
			for (int j=0; j<g[i].size(); j++) {
				if (l[g[i] [j]]!=0) {
					g[i] [j]=l[g[i] [j]];
				}
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (l[i]==0) {
			for (int j=0; j<v[i].size(); j++) {
				if (l[v[i] [j]]==0) {
					g[i].push_back(v[i] [j]);
					g[v[i] [j]].push_back(i);
				} else {
					g[i].push_back(l[v[i] [j]]);
				}
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (!g[i].empty()) root=i;
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
	}
	if (root==0) root=n+1;
	mp(root, 0, 0);
	for (int i=1; i<cnt; i++) {
		if (parr[i] [0]!=0) tree.push_back(i);
	}
	for (int i=1; i<17; i++) {
		for (int j=0; j<tree.size(); j++) {
			int node=tree[j];
			parr[node] [i]=parr[parr[node] [i-1]] [i-1];
		}
	}
	q=read();
	for (int i=0; i<q; i++) {
		x=read();
		y=read();
		int xx, yy;
		if (l[x]==0) xx=x; else xx=l[x];
		if (l[y]==0) yy=y; else yy=l[y];
		if (dub[xx]<dub[yy]) swap(xx, yy);
		int k=lca(xx, yy), pot;
		if (k==yy) {
			if (yy==root) {
				pot=sum[xx];
			} else {
				pot=sum[xx]-sum[parr[yy] [0]];
			}
		} else {
			if (k==root) {
				pot=sum[xx]+sum[yy]-sum[root];
			} else {
				pot=sum[xx]+sum[yy]-sum[parr[k] [0]]-sum[k];
			}
		}
		printf("%d\n", (int) po(2, pot));
	}
	return 0;
}