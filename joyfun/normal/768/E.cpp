#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 65;

int s[61] = {0, 1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
int n;
map<ll, int> sg[N];

int dfs(int u, ll s) {
	if (sg[u].count(s)) return sg[u][s];
	set<int> sb;
	for (int i = 1; i <= 60 && i <= u; i++) {
		if (s>>i&1) continue;
		sb.insert(dfs(u - i, s|(1<<i)));
	}
	for (int i = 0; ;i++) {
		if (sb.find(i) == sb.end()) {
			sg[u][s] = i;
			return i;
		}
	}
}

int main() {
	//for (int i = 1; i <= 60; i++) dfs(i, 0ll);
	int n, x, sum = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		sum ^= s[x];
	}
	printf("%s\n", sum ? "NO" : "YES");
	return 0;
}