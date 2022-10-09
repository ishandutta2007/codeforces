#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[300005];
basic_string<int> e[300005], f[300005];
bool drug[300005];

bool ima(int u, int v) {
	auto it = lower_bound(e[u].begin(), e[u].end(), v);
	if (it == e[u].end())
		return false;
	return *it == v;
}

bool moze(const basic_string<int>& a, basic_string<int>& b) {
	// da li je b podskup od a
	if (b.size() > a.size())
		return false;
	sort(b.begin(), b.end());
	size_t j = 0;
	for (int x : a) {
		if (j != b.size() && x == b[j])
			j++;
	}
	return j == b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		f[v] += u;
	}

	int last = a[n];

	for (int i=1; i<=n; i++) {
		sort(e[i].begin(), e[i].end());
		sort(f[i].begin(), f[i].end());
	}

	for (int x : f[last])
		drug[x] = 1;

	int sol = 0;
	basic_string<int> treba;
	for (int i=n-1; i>=1; i--) {
		if (drug[a[i]]) {
			// proveri da li moze da se swapuje sa svima sa kojima treba
			if (moze(e[a[i]], treba)) {
				sol++;
			} else {
				treba += a[i];
			}
		} else {
			treba += a[i];
		}
	}
	cout << sol << '\n';
}