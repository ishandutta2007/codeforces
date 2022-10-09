#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M1 = 1000000007;
const int M2 = 1000000009;
const int B = 43141321;

int n, k, g;
string s;
int z1[1100005], z2[1100005], p1[1100005], p2[1100005];
tuple<int, int, int> hw[100005];

pair<int, int> gethash(int l, int r) {
	int h1 = z1[r] - z1[l] * 1ll * p1[r-l] % M1;
	if (h1 < 0) h1 += M1;

	int h2 = z2[r] - z2[l] * 1ll * p2[r-l] % M2;
	if (h2 < 0) h2 += M2;

	return {h1, h2};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	s += s;
	cin >> g;
	for (int i=0; i<g; i++) {
		string w;
		cin >> w;

		int h1 = 0, h2 = 0;
		for (char x : w) {
			h1 = (h1 * 1ll * B + x) % M1;
			h2 = (h2 * 1ll * B + x) % M2;
		}

		hw[i] = {h1, h2, i+1};
	}

	sort(hw, hw+g);

	p1[0] = p2[0] = 1;
	for (int i=0; i<n*k+k; i++) {
		z1[i+1] = (z1[i] * 1ll * B + s[i]) % M1;
		z2[i+1] = (z2[i] * 1ll * B + s[i]) % M2;
		p1[i+1] = p1[i] * 1ll * B % M1;
		p2[i+1] = p2[i] * 1ll * B % M2;
	}

	for (int i=0; i<k; i++) {
		basic_string<pair<int, int>> parts, tmp;
		for (int j=0; j<n; j++) {
			auto h = gethash(j*k+i, j*k+i+k);
			parts += h;
		}
		tmp = parts;
		sort(tmp.begin(), tmp.end());
		auto it = unique(tmp.begin(), tmp.end());
		if (it != tmp.end())
			continue;

		bool ok = 1;
		basic_string<int> idxs;
		for (auto h : parts) {
			auto it = lower_bound(hw, hw+g, make_tuple(h.first, h.second, -1));
			if (it == hw+g || get<0>(*it) != h.first || get<1>(*it) != h.second) {
				ok = 0;
				break;
			}
			idxs += get<2>(*it);
		}

		if (ok) {
			cout << "YES\n";
			for (int x : idxs)
				cout << x << ' ';
			cout << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}