#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 100005;
const int INF = 1000000007;

int n, m, cnt;
long long sol;
int val[MAXN], bio[MAXN], mini[MAXN];
vector <int> v[MAXN];

void dfs (int cvor, int boja) {
	if (bio[cvor]) return;
	bio[cvor]=boja;
	mini[boja]=min(mini[boja], val[cvor]);
	for (int i=0; i<v[cvor].size(); i++) {
		dfs(v[cvor] [i], boja);
	}
}

int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		scanf("%d", &val[i]);
		mini[i]=INF;
	}
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) {
			cnt++;
			dfs(i, cnt);
			sol+=mini[cnt];
		}
	}
	cout << sol;
	return 0;
}