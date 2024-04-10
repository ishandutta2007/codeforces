#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 100005;

int n, m, sol;
int col[MAXN], deg[MAXN], bio[MAXN];
vector <int> v[MAXN];
set < pair <int, int> > s, t;

void korak () {
	while (s.size()>0) {
		int x=s.begin()->second;
		if (deg[x]>0) break;
		bio[x]=1;
		s.erase(s.begin());
		for (int i=0; i<v[x].size(); i++) {
			int sus=v[x] [i];
			if (bio[sus]) continue;
			if (col[sus]==0) s.erase(make_pair(deg[sus], sus)); else t.erase(make_pair(deg[sus], sus));
			deg[sus]--;
			if (col[sus]==0) s.insert(make_pair(deg[sus], sus)); else t.insert(make_pair(deg[sus], sus));
		}
	}
	if (s.size()==0 && t.size()==0) return;
	sol++;
	while (t.size()>0) {
		int x=t.begin()->second;
		if (deg[x]>0) break;
		bio[x]=1;
		t.erase(t.begin());
		for (int i=0; i<v[x].size(); i++) {
			int sus=v[x] [i];
			if (bio[sus]) continue;
			if (col[sus]==0) s.erase(make_pair(deg[sus], sus)); else t.erase(make_pair(deg[sus], sus));
			deg[sus]--;
			if (col[sus]==0) s.insert(make_pair(deg[sus], sus)); else t.insert(make_pair(deg[sus], sus));
		}
	}
	if (s.size()==0 && t.size()==0) return;
	korak();
}

int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		scanf("%d", &col[i]);
	}
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a++; b++;
		v[b].push_back(a);
		deg[a]++;
	}
	for (int i=1; i<=n; i++) {
		if (col[i]==0) {
			s.insert(make_pair(deg[i], i));
		} else {
			t.insert(make_pair(deg[i], i));
		}
	}
	korak();
	cout << sol;
	return 0;
}