#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 300005;

int n, m, odd;
int a[MAXN], b[MAXN], w[MAXN], par[MAXN], siz[MAXN], sol[MAXN];
vector < pair <int, int> > st;
vector <int> saz, v[MAXN];

void sazimanje () {
	for (int i=0; i<m; i++) {
		saz.push_back(w[i]);
	}
	sort(saz.begin(), saz.end());
	saz.erase(unique(saz.begin(), saz.end()), saz.end());
	for (int i=0; i<m; i++) {
		w[i]=lower_bound(saz.begin(), saz.end(), w[i])-saz.begin()+1;
	}
}

void dsu () {
	odd=n;
	for (int i=1; i<=n; i++) {
		par[i]=i;
		siz[i]=1;
	}
}

int nadi (int x) {
	if (x==par[x]) return x; return nadi(par[x]);
}

void spoji (int a, int b) {
	a=nadi(a); b=nadi(b);
	if (siz[a]<siz[b]) swap(a, b);
	st.push_back(make_pair(a, b));
	if (a==b) return;
	odd-=(siz[a]&1) + (siz[b]&1);
	siz[a]+=siz[b];
	par[b]=a;
	odd+=siz[a]&1;
}

void makni () {
	int a=st.back().first;
	int b=st.back().second;
	st.pop_back();
	if (a==b) return;
	odd-=siz[a]&1;
	par[b]=b;
	siz[a]-=siz[b];
	odd+=(siz[a]&1) + (siz[b]&1);
}

void dvc (int l, int r, int lo, int hi) {
	if (l>r) return;
	int md=(l+r)/2, val;
	int br=st.size();
	for (int i=l; i<=md; i++) {
		if (w[i]<=lo) spoji(a[i], b[i]);
	}
	if (odd==0) {
		val=lo;
	} else {
		val=hi;
		for (int i=lo+1; i<=hi; i++) {
			for (int j=0; j<v[i].size(); j++) {
				int e=v[i] [j];
				if (e>md) break;
				spoji(a[e], b[e]);
			}
			if (odd==0) {
				val=i;
				break;
			}
		}
	}
	sol[md]=val;
	while (st.size()>br) makni();
	for (int i=lo+1; i<=val; i++) {
		for (int j=0; j<v[i].size(); j++) {
			int e=v[i] [j];
			if (e>l) break;
			spoji(a[e], b[e]);
		}
	}
	dvc(l, md-1, val, hi);
	while (st.size()>br) makni();
	for (int i=l; i<=md; i++) {
		if (w[i]<=lo) spoji(a[i], b[i]);
	}
	dvc(md+1, r, lo, val);
	while (st.size()>br) makni();
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &w[i]);
	}
	sazimanje();
	dsu();
	for (int i=0; i<m; i++) {
		v[w[i]].push_back(i);
	}
	dvc(0, m-1, 1, MAXN-3);
	for (int i=0; i<m; i++) {
		if (sol[i]==MAXN-3) printf("-1\n"); else printf("%d\n", saz[sol[i]-1]);
	}
	return 0;
}