#include<iostream>
#include<vector>

using namespace std;

typedef long long llint;

const int MAXN = 150005;

int n, m, a, b, cnt, ok=1;
vector <int> v[MAXN];
int bio[MAXN];
llint brid[MAXN];
llint l[MAXN];

void dfs (int cvor) {
	if (bio[cvor]) return;
	bio[cvor]=cnt;
	for (int i=0; i<v[cvor].size(); i++) {
		dfs(v[cvor] [i]);
	}
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) {
			cnt++;
			dfs(i);
		}
	}
	for (int i=1; i<=n; i++) {
		l[bio[i]]++;
		brid[bio[i]]+=((llint) v[i].size());
	}
	for (int i=1; i<=n; i++) {
		if (l[i]*(l[i]-1)!=brid[i]) ok=0;
	}
	if (ok) cout << "YES"; else cout << "NO";
	return 0;
}