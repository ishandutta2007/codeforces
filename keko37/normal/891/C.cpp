#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

const int MAXN = 500005;

int n, m, q;
int pos[MAXN], par[MAXN];
vector <int> g[MAXN];
vector < pair <int, int> > u[MAXN], st;
bool sol[MAXN];

struct edge {
	int a, b, w;
} l[MAXN];

int nadi (int x) {
	if (par[x]==x) return x; return nadi(par[x]);
}

bool spoji (int a, int b) {
	a=nadi(a); b=nadi(b);
	if (pos[a]<pos[b]) swap(a, b);
	st.push_back(make_pair(a, b));
	if (a==b) return 0;
	pos[a]+=pos[b];
	par[b]=a;
	return 1;
}

void makni () {
	int a=st.back().first;
	int b=st.back().second;
	st.pop_back();
	if (a==b) return;
	pos[a]-=pos[b];
	par[b]=b;
}
 
inline bool is (char cc) {
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
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		par[i]=i;
		pos[i]=1;
	}
	for (int i=0; i<m; i++) {
		l[i].a=read(); l[i].b=read(); l[i].w=read();
		g[l[i].w].push_back(i);
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		sol[i]=1;
		int k, ind;
		k=read();
		for (int j=0; j<k; j++) {
			ind=read();
			u[l[ind-1].w].push_back(make_pair(ind-1, i));
		}
	}
	for (int val=1; val<MAXN; val++) {
		int cnt=0;
		for (int i=0; i<u[val].size(); i++) {
			if (i==0 || u[val] [i-1].second!=u[val] [i].second) {
				for (int j=0; j<cnt; j++) {
					makni();
				}
				cnt=0;
			}
			int e=u[val] [i].first;
			sol[u[val] [i].second] &= spoji(l[e].a, l[e].b);
			cnt++;
		}
		for (int j=0; j<cnt; j++) {
			makni();
		}
		for (int i=0; i<g[val].size(); i++) {
			int e=g[val] [i];
			spoji(l[e].a, l[e].b);
		}
	}
	for (int i=0; i<q; i++) {
		if (sol[i]) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}