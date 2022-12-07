#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 30;
int n;
map<int, int> dp;
int s[35];

int dfs(int S) {
	if (dp.count(S)) return dp[S];
	int sg = 0;
	for (int i = 0; i < 30; i++) if (S>>i&1) {
		sg |= (1<<dfs((((1<<30) - 1)^s[i])&S));
	}
	for (int i = 0; ; i++) if ((sg&(1<<i)) == 0) {
		dp[S] = i;
		break;
	}
	return dp[S];
}

int sg(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 1;
	if (x == 4) return 4;
	if (x == 5) return 3;
	if (x == 6) return 2;
	if (x == 7) return 1;
	if (x == 8) return 5;
	if (x == 9) return 6;
	if (x == 10) return 2;
	if (x == 11) return 1;
	if (x == 12) return 8;
	if (x == 13) return 7;
	if (x == 14) return 5;
	if (x == 15) return 9;
	if (x == 16) return 8;
	if (x == 17) return 7;
	if (x == 18) return 3;
	if (x == 19) return 4;
	if (x == 20) return 7;
	if (x == 21) return 4;
	if (x == 22) return 2;
	if (x == 23) return 1;
	if (x == 24) return 10;
	if (x == 25) return 9;
	if (x == 26) return 3;
	if (x == 27) return 6;
	if (x == 28) return 11;
	if (x == 29) return 12;
	if (x == 30) return 14;
}

int vis[1000005];

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	int f = 0;
	for (int i = 2; i * i <= n; i++) {
		if (vis[i]) continue;
		int tmp = 0;
		for (ll j = i; j <= n; j *= i) {
			if (j < 1000005) vis[j] = 1;
			tmp++;
		}
	//	printf("%d %d\n", i, tmp);
		sum += tmp;
		f ^= sg(tmp);
	}
	n -= sum;
	f ^= (n % 2);
	printf("%s\n", f ? "Vasya" : "Petya");
	return 0;
}