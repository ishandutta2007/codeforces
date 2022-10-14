#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 300005;

int n, m;
int d[MAXN], a[MAXN], b[MAXN];
int par[MAXN], val[MAXN], naso[MAXN], p[MAXN];
vector <pair <int, int> > v[MAXN];
vector <int> sol;

int nadi (int cvor) {
	if (par[cvor]==cvor) return cvor;
	return par[cvor]=nadi(par[cvor]);
}

bool spoji (int x, int y) {
	x=nadi(x);
	y=nadi(y);
	if (x==y) return 0;
	par[x]=y;
	return 1;
}

void ispis () {
	for (int i=1; i<=n; i++) {
		cout << i << "  ";
		for (int j=0; j<v[i].size(); j++) {
			cout << v[i] [j].first << " ";
		}
		cout << endl;
	}
}

int f (int cvor, int rod) {
	naso[cvor]=-1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].first;
		if (sus==rod) continue;
		int t=f(sus, cvor);
		if (t==-1) {
			naso[cvor]=sus;
		} else {
			val[cvor]^=t;
			if (t) sol.push_back(v[cvor] [i].second);
		}
	}
	if (d[cvor]==-1) {
		p[cvor]=-1;
		return -1;
	}
	if (naso[cvor]!=-1) {
		p[cvor]=-1;
		return -1;
	} else {
		if (val[cvor]!=d[cvor]) p[cvor]=1;
		if (val[cvor]==d[cvor]) return 0; else return 1;
	}
}

void rjesi (int cvor, int rod) {
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].first;
		if (sus==rod) continue;
		int t=p[sus];
		if (t==-1 && sus==naso[cvor] && d[cvor]!=-1) {
			if (val[cvor]!=d[cvor]) {
				sol.push_back(v[cvor] [i].second);
				val[sus]=!val[sus];
			}
		}
		rjesi(sus, cvor);
	}
}

int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		scanf("%d", &d[i]);
		par[i]=i;
	}
	for (int i=0; i<m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		if (!spoji(a[i], b[i])) continue;
		v[a[i]].push_back(make_pair(b[i], i+1));
		v[b[i]].push_back(make_pair(a[i], i+1));
	}
	if (f(1, -1)==1) {
		cout << -1;
	} else {
		rjesi(1, -1);
		cout << sol.size() << endl;
		for (int i=0; i<sol.size(); i++) {
			printf("%d ", sol[i]);
		}
	}
	return 0;
}