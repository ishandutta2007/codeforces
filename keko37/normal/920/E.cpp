#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>

using namespace std;

const int MAXN = 200005;

int n, m;
long long par[MAXN], siz[MAXN];
set <int> s, v[MAXN];
set <int> :: iterator it, it1, it2;
map <int, map <int, int> > mp;
multiset <int> ms;
multiset <int> :: iterator it3;
vector < pair <int, int> > e, novi;

int nadi (int x) {
	if (par[x]==x) return x;
	return par[x]=nadi(par[x]);
}

void spoji (int a, int b) {
	a=nadi(a);
	b=nadi(b);
	if (a==b) return;
	siz[a]+=siz[b];
	par[b]=a;
}

void f (int x) {
	if (s.find(x)==s.end()) return;
	s.erase(x);
	for (int i=1; i<=n; i++) {
		if (v[x].find(i)!=v[x].end()) continue;
		spoji(x, i);
		s.erase(i);
	}
}

int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		par[i]=i;
		siz[i]=1;
		s.insert(i);
	}
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e.push_back(make_pair(a, b));
		v[a].insert(b);
		v[b].insert(a);
	}
	for (int i=1; i<=n; i++) {
		f(i);
	}
	for (int i=1; i<=n; i++) {
		s.insert(nadi(i));
	}
	for (int i=0; i<e.size(); i++) {
		mp[nadi(e[i].first)] [nadi(e[i].second)]++;
		mp[nadi(e[i].second)] [nadi(e[i].first)]++;
	}
	for (it1=s.begin(); it1!=s.end(); it1++) {
		for (it2=it1; it2!=s.end(); it2++) {
			if (*it1==*it2) continue;
			if (siz[*it1]*siz[*it2]>mp[*it1] [*it2]) novi.push_back(make_pair(*it1, *it2));
		}
	}
	for (int i=0; i<novi.size(); i++) {
		spoji(novi[i].first, novi[i].second);
	}
	s.clear();
	for (int i=1; i<=n; i++) {
		if (par[i]==i) ms.insert(siz[i]);
	}
	cout << ms.size() << endl;
	for (it3=ms.begin(); it3!=ms.end(); it3++) {
		printf("%d ", *it3);
	}
	return 0;
}