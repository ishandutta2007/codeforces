#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 32000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

int eulerphi(int x) {
	auto v = factor(x);
	int y = x;
	for (auto [p, a] : v)
		y = y/p*(p-1);
	return y;
}

int n, m, mseq[42];

int mul_of(int x, int y) {
	ll z = 1ll*x*y;
	return min(z, 1'000'000'007ll);
}

int mul_mod(int x, int y, int m) {
	return x*1ll*y % m;
}

int pw_of(int x, int y) {
	if (y == 0)
		return 1;
	int z = pw_of(x, y >> 1);
	z = mul_of(z, z);
	if (y & 1)
		z = mul_of(z, x);
	return z;
}

int pw_mod(int x, int y, int m) {
	if (y == 0 || x == 1 || m == 1)
		return 1 % m;
	int z = pw_mod(x, y >> 1, m);
	z = mul_mod(z, z, m);
	if (y & 1)
		z = mul_mod(z, x, m);
	return z;
}

int a[100005];

pair<int, int> solve(int l, int r, int lvl) {
	if (lvl == 40 || l == r || a[l] == 1)
		return {a[l] % mseq[lvl], a[l]};
	auto [md, of] = solve(l+1, r, lvl+1);

	// cerr << "got " << md << ' ' << of << " za " << l << ' ' << r << ' ' << lvl << '\n';

	int xp = of != md ? md + mseq[lvl+1] : md;

	// cerr << "xp = " << xp << '\n';

	return {pw_mod(a[l], xp, mseq[lvl]), pw_of(a[l], of)};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	mseq[0] = m;
	for (int i=1; i<42; i++)
		mseq[i] = eulerphi(mseq[i-1]);

	for (int i=1; i<=n; i++)
		cin >> a[i];

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << solve(l, r, 0).first << '\n';
	}
}