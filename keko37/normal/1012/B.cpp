#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 200005;

int n, m, q, cnt, sol;
int r[MAXN], bio[MAXN];
vector <int> l[MAXN], v[MAXN];

void dfs (int x) {
	if (bio[x]) return;
	bio[x] = cnt;
	for (int i=0; i<v[x].size(); i++) {
		dfs(v[x] [i]);
	}
}

int main () {
	cin >> n >> m >> q;
	for (int i=0; i<q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		l[x].push_back(y);
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<l[i].size(); j++) {
			int s = l[i] [j];
			if (r[s]) {
				v[i].push_back(r[s]);
				v[r[s]].push_back(i);
			}
			r[s] = i;
		}
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) {
			cnt++;
			dfs(i);
		}
	}
	for (int i=1; i<=m; i++) {
		if (r[i] == 0) sol++;
	}
	cout << sol + cnt-1;
	return 0;
}