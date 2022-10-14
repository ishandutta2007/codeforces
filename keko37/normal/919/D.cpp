#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 300005;

int n, m, naso, sol;
int bio[MAXN], dp[MAXN] [30];
char s[MAXN];
vector <int> v[MAXN];

void dfs (int x) {
	if (naso) return;
	bio[x]=1;
	for (int i=0; i<v[x].size(); i++) {
		int sus=v[x] [i];
		if (bio[sus]==0) {
			dfs(sus);
		} else if (bio[sus]==1) {
			naso=1;
			return;
		}
		if (naso) return;
	}
	bio[x]=2;
}

void f (int x) {
	if (bio[x]==3) return;
	bio[x]=3;
	for (int i=0; i<v[x].size(); i++) {
		int sus=v[x] [i];
		f(sus);
		for (int j=0; j<26; j++) {
			dp[x] [j]=max(dp[x] [j], dp[sus] [j]);
		}
		sol=max(sol, dp[x] [s[sus]-'a']);
	}
	dp[x] [s[x]-'a']++;
	sol=max(sol, dp[x] [s[x]-'a']);
}

int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> s[i];
	}
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) dfs(i);
	}
	if (naso) {
		cout << -1;
		return 0;
	}
	for (int i=1; i<=n; i++) {
		f(i);
	}
	cout << sol;
	return 0;
}