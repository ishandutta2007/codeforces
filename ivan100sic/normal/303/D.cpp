// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string baseform(int x, int b, int l) {
	string s;
	while (l--) {
		s += (char)(x % b + 48);
		x /= b;
	}
	reverse(begin(s), end(s));
	return s;
}

void proba() {
	for (int b=2; b<=10; b++) {
		for (int l=1; pow(b, l)<=1e9; l++) {
			int found = 0;
			for (int x=1; x*l < pow(b, l) && !found; x++) {
				string s = baseform(x, b, l);
				int ok = 1;
				for (int mul=2; mul<=l; mul++) {
					string p = baseform(x * mul, b, l);
					if ((p+p).find(s) == string::npos) {
						ok = 0;
						break;
					}
				}
				if (ok) {
					found = 1;
					cerr << b << ' ' << l << ' ' << s << '\n';
					break;
				}
			}
		}
	}
}

// nadji b:
// b^n - 1 = 0 (mod n+1)


const int SITO_MAX = 5000005;

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

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

int pw(int x, int y, int m) {
	if (y == 0)
		return 1 % m;
	if (y == 1)
		return x % m;
	int z = pw(x, y >> 1, m);
	z = z * 1ll * z % m;
	if (y & 1)
		z = z * 1ll * x % m;
	return z;
}

vector<pair<int, int>> v;

int isprc[5000005];

bool is_primitive_root_nocache(int b, int m) {
	for (auto [pr, e] : v)
		if (pw(b, (m-1)/pr, m) == 1)
			return false;
	return true;
}

void resi_prc(int m) {
	int q = 2;
	while (!is_primitive_root_nocache(q, m))
		q++;
	for (int i=1, p=q; i<m; i++, p=p*1ll*q%m) {
		if (gcd(i, m-1) == 1) {
			isprc[p] = 1;
		} else {
			isprc[p] = 0;
		}
	}
}

int resi(int n, int x) {
	// n+1 prost
	if (f[n+1] != n+1)
		return -1;
	if (n == 1)
		return x == 2 ? -1 : x-1;

	v = factor_small(n);
	resi_prc(n+1);
	int sol = -1;
	for (int r=1; r<=n && r<x; r++) {
		int b = (x-1-r)/(n+1)*(n+1) + r;
		if (isprc[r]) {
			sol = max(sol, b);
		}
	}

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(isprc, 0xff, sizeof isprc);

	int n, x;
	cin >> n >> x;
	cout << resi(n, x) << '\n';
	
}

// I will still practice daily...
// 001001
// 010010
// 011011
// 100100
// 101101
// 110110

// 222201111002020010100012000021111220202212122210
// 222201111002020010100012000021111220202212122210