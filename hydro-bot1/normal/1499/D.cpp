// Hydro submission #61975a45d28d95852ab35c13@1637309001579
#include <bits/stdc++.h>
using namespace std;
#define N 20000010

int vis[N], f[N], c, d, x, res;
vector<int> pr;

void Euler() { f[0] = f[1] = 1;
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) pr.push_back(i), f[i] = 2;
		for (int j = 0; j < pr.size() && i * pr[j] < N; j ++) {
			vis[i * pr[j]] = 1, f[i * pr[j]] = f[i];
			if (i % pr[j] == 0) break; else f[i * pr[j]] <<= 1;
		}
	}
}

int main() {
	int T; cin >> T, Euler(); while (T --, cin >> c >> d >> x) {
		for (int g = 1; g * g <= x; g ++) if (x % g == 0) {
			if ((x / g + d) % c == 0) res += f[(x / g + d) / c];
			if ((g + d) % c == 0 && g * g != x) res += f[(g + d) / c];
		}
		cout << res << endl, res = 0;
	}
	return 0;
}