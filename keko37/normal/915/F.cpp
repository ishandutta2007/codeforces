#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

int n;
int a[MAXN], par[MAXN], bio[MAXN];
llint siz[MAXN], val[MAXN], sol;
vector <int> v[MAXN];
vector < pair <int, int> > t;

void dsu_init () {
	for (int i=1; i<=n; i++) {
		bio[i]=0;
		val[i]=0;
		par[i]=i;
		siz[i]=1;
	}
}

int nadi (int x) {
	if (par[x]==x) return x; return par[x]=nadi(par[x]);
}

void spoji (int x, int y) {
	x=nadi(x); y=nadi(y);
	if (x==y) return;
	siz[x]+=siz[y];
	par[y]=x;
}

void ubaci (int x) {
	bio[x]=1;
	llint sum=0;
	for (int i=0; i<v[x].size(); i++) {
		int sus=v[x] [i];
		if (!bio[sus]) continue;
		int novi=siz[nadi(sus)];
		val[x]+=sum*novi;
		sum+=novi;
		spoji(x, sus);
	}
	val[x]+=siz[nadi(x)];
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		t.push_back(make_pair(a[i], i));
	}
	sort(t.begin(), t.end());
	for (int i=0; i<n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dsu_init();
	for (int i=0; i<n; i++) {
		ubaci(t[i].second);
		sol+=val[t[i].second]*a[t[i].second];
	}
	dsu_init();
	for (int i=n-1; i>=0; i--) {
		ubaci(t[i].second);
		sol-=val[t[i].second]*a[t[i].second];
	}
	cout << sol;
	return 0;
}