#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 55;
const int mod = 1e9 + 7;
int n, k[2], u[2][7070], dp[2][7070], l[2][7070], vis[2][7070];
void dfs(int i, int j, int uwu = 0) {
	if(vis[i][j]) return;
	vis[i][j] = 1;
	dp[i][j] = 1 + uwu;
	if(!uwu) {
		for(int a = 0; a < k[i^1]; a++) {
			int owo = (n+j-u[i^1][a])%n;
			if(owo)
				dfs(i^1, owo, 1);
		}
	} else {
		for(int a = 0; a < k[i^1]; a++) {
			int owo = (n+j-u[i^1][a])%n;
			if(owo&&--l[i^1][owo]==0)
				 dfs(i^1, owo, 0);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < 2; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
			cin >> u[i][j];
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			l[i][j] = k[i];
	dfs(0, 0);
	dfs(1, 0);
	string st[] = { "Loop", "Lose", "Win"};
	for (int i = 0; i < 2; i++, cout << "\n")
		for (int j = 1; j < n; j++)
			cout << st[dp[i][j]] << " ";
}