#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll f_cache[100005];

ll f_greedy(int n, int b) {
	if (f_cache[n] != -1)
		return f_cache[n];
	if (n <= 1)
		return n;
	ll sol = 1;
	for (int i=0; i<b; i++) {
		ll x = (n-1ll)*(i+1)/b - (n-1ll)*i/b;
		sol += f_greedy(x, b) + x;
	}
	return f_cache[n] = sol;
}

int dub[100005];

ll greedy_upper(int x, int d, int n, int o) {
	return n*(n+2*d-1ll) / 2;
}

// x je prosli, d je dubina sada, n je broj cvorova, o je faktor 
ll greedy_lower(int x, int d, int n, int o) {
	if (o == 1) {
		return greedy_upper(x, d, n, o);
	}
	ll val = 0;
	for (int i=0; n > 0; i++) {
		int curr = min(o*1ll*x, (ll)n);
		val += (d+i) * curr;
		x = curr;
		n -= curr;
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	ll s;
	cin >> n >> s;
	if (s > n*(n+1ll) / 2) {
		cout << "No\n";
		return 0;
	}
	if (s < 2*n-1) {
		cout << "No\n";
		return 0;
	}
	// ima resenje, trazi ga binarno
	ll l = 1, r = n-1, o = -1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		memset(f_cache, 255, sizeof(f_cache));
		ll x = f_greedy(n, m);
		if (x <= s) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cerr << "branching: " << o << '\n';
	// konstruisi resenje
	dub[1] = 1;
	int ostalo = n-1;
	ll zbir_ostalo = s - 1;
	for (int d=2; ostalo > 0; d++) {
		for (int i=1; i<=ostalo; i++) {
			if (greedy_lower(i, d+1, ostalo-i, o) <= zbir_ostalo - i*1ll*d
				&& zbir_ostalo - i*1ll*d <= greedy_upper(i, d+1, ostalo-i, o))
			{
				dub[d] = i;
				zbir_ostalo -= i*1ll*d;
				ostalo -= i;
				break;
			}
		}
	}

	cout << "Yes\n";
	vector<queue<pair<int, int>>> adopter(n+1);
	adopter[1].push({1, o});
	int nd = 1;
	for (int d=2; dub[d]; d++) {
		for (int i=0; i<dub[d]; i++) {
			auto& p = adopter[d-1].front();
			cout << p.first << ' ';
			p.second--;
			if (p.second == 0)
				adopter[d-1].pop();
			++nd;
			adopter[d].push({nd, o});
		}
	}
	cout << '\n';
}