#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 10005;

int n;
int p[MAXN], c[MAXN], dp[MAXN];
vector <int> v[MAXN];

void dfs (int x) {
	dp[x]=1;
	for (int i=0; i<v[x].size(); i++) {
		dfs(v[x] [i]);
		dp[x]+=dp[v[x] [i]];
		if (c[x]==c[v[x] [i]]) dp[x]--;
	}
}

int main () {
	cin >> n;
	for (int i=2; i<=n; i++) {
		scanf("%d", &p[i]);
		v[p[i]].push_back(i);
	}
	for (int i=1; i<=n; i++) {
		scanf("%d", &c[i]);
	}
	dfs(1);
	cout << dp[1];
	return 0;
}