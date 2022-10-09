#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> gaus(vector<int> b) {
	int f = 0, n = b.size();
	for (int i=30; i>=0; i--) {
		int j = -1;
		for (int k=f; k<n; k++)
			if (b[k] & (1 << i)) {
				j = k;
				break;
			}
		if (j != -1) {
			swap(b[j], b[f]);
			f++;
			for (int k=f; k<n; k++)
				if (b[k] & (1 << i))
					b[k] ^= b[f-1];
		}			
	}

	b.erase(b.begin() + f, b.end());
	return b;
}

vector<int> generisi(int n) {
	vector<int> b;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int k = j + j-i;
			if (k >= n)
				continue;
			b.push_back((1 << i) + (1 << j) + (1 << k));
		}
	}
	return b;
}

vector<int> gen12() {
	const int N = 6;

	vector<int> potezi = generisi(2 * N);

	return potezi;
}

void igraj_se() {
	const int N = 6;

	vector<int> potezi = generisi(2 * N);
	auto it = remove_if(potezi.begin(), potezi.end(), [](int x) {
		return (x & -x) >= (1 << N);
	});
	potezi.erase(it, potezi.end());

	cerr << potezi.size() << '\n';
	for (int x : potezi)
		cout << bitset<2*N>(x) << '\n';

	set<int> s;

	for (int x : potezi)
	for (int y : potezi)
	{
		s.insert((x ^ y) & ((1 << N) - 1));
	}
	cerr << s.size() << '\n';
}

int n;
int a[100005];

struct stvar {
	int x, y, z;
};

vector<stvar> sol;

void mv(int offs, int mask) {
	bitset<32> b(mask);
	stvar s = {-1, -1, -1};
	for (int i=0; i<32; i++) {
		if (b[i]) {
			if (s.x == -1)
				s.x = i + offs;
			else if (s.y == -1)
				s.y = i + offs;
			else
				s.z = i + offs;
		}
	}
	sol.push_back(s);
	a[s.x] ^= 1;
	a[s.y] ^= 1;
	a[s.z] ^= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	auto g = gen12();

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	// svedi na 8-13
	int k = n;
	while (k > 13) {
		for (int x : g) {
			bool broke = false;
			for (int y : g) {
				bitset<6> z((x ^ y) >> 6);
				bool ok = true;
				for (int i=0; i<6; i++) {
					if ((int)z[i] != a[k - 5 + i])
						ok = false;
				}
				if (ok) {
					mv(k - 11, x);
					mv(k - 11, y);
					broke = true;
					break;
				}
			}
			if (broke)
				break;
		}

		k -= 6;
	}

	// svedi na 8
	while (k > 8) {
		if (a[k])
			mv(k-2, 7);
		k--;
	}

	int tgt = 0;
	for (int i=0; i<k; i++)
		tgt |= a[i+1] << i;

	cerr << k << ' ' << bitset<8>(tgt) << '\n';

	// resi brut za 8 ili sta god je ostalo
	vector<int> h = generisi(k);
	for (size_t mask = 0; mask < (1u << h.size()); mask++) {
		int kand = 0;
		for (size_t i = 0; i < h.size(); i++)
			if (mask & (1 << i))
				kand ^= h[i];
		if (kand == tgt) {

			for (size_t i = 0; i < h.size(); i++)
				if (mask & (1 << i))
					mv(1, h[i]);

			cout << "YES\n";
			cout << sol.size() << '\n';
			for (auto p : sol)
				cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
			return 0;
		}
	}

	cout << "NO\n";
}