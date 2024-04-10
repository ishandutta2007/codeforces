#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct cc {
	int c00, c01, c10, c11;
};

const int MOD = 1'000'000'007;

int pw(int x, int y) {
	if (y == 0)
		return 1;

	int z = pw(x, y >> 1);
	z = z * 1ll * z % MOD;
	if (y & 1) {
		z = z * 1ll * x % MOD;
	}
	return z;
}

int f[200005];
int finv[200005];

int bc(int n, int k) {
	if (k < 0 || n < 0 || n - k < 0)
		return 0;
	return f[n] * 1ll * finv[k] % MOD * finv[n - k] % MOD;
}

int ubaci(int n, int k) {
	if (n < 0 || k < 0) {
		return 0;
	}

	if (n == 0) {
		if (k == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	return bc(n + k - 1, k);
}

bool valid(cc b) {
	return b.c00 >= 0 && b.c01 >= 0 && b.c10 >= 0 && b.c11 >= 0;
}

int solve1(cc b) {
	if (!valid(b)) {
		return 0;
	}

	if (b.c10 == b.c01) {
		int n1 = b.c10 + 1;
		int n0 = b.c10;
		int k1 = b.c11;
		int k0 = b.c00;
		// 1 ... 1
		int t = ubaci(n0, k0);
		t = t * 1ll * ubaci(n1, k1) % MOD;
		return t;
	}
	else if (b.c10 == b.c01 + 1) {
		int n1 = b.c10;
		int n0 = n1;
		int k1 = b.c11;
		int k0 = b.c00;
		// 1 ... 0
		int t = ubaci(n0, k0);
		t = t * 1ll * ubaci(n1, k1) % MOD;
		return t;
	}
	return 0;
}

int solve0(cc b) {
	if (!valid(b)) {
		return 0;
	}

	if (b.c10 == b.c01) {
		int n1 = b.c10;
		int n0 = b.c10 + 1;
		int k1 = b.c11;
		int k0 = b.c00;
		// 0 ... 0
		int t = ubaci(n0, k0);
		t = t * 1ll * ubaci(n1, k1) % MOD;
		return t;
	}
	else if (b.c01 == b.c10 + 1) {
		int n1 = b.c01;
		int n0 = n1;
		int k1 = b.c11;
		int k0 = b.c00;
		// 0 ... 1
		int t = ubaci(n0, k0);
		t = t * 1ll * ubaci(n1, k1) % MOD;
		return t;
	}
	return 0;
}

bool dobar(string s, cc b) {
	for (int i = 0; i + 1 < (int)s.size(); i++) {
		if (s[i] == '0' && s[i + 1] == '0') {
			b.c00--;
		}
		else if (s[i] == '0' && s[i + 1] == '1') {
			b.c01--;
		}
		else if (s[i] == '1' && s[i + 1] == '0') {
			b.c10--;
		}
		else {
			b.c11--;
		}
	}
	return b.c00 == 0 && b.c01 == 0 && b.c10 == 0 && b.c11 == 0;
}

// <= s
int solve(string s, cc b) {
	int n = b.c00 + b.c01 + b.c10 + b.c11 + 1;

	int m = s.size();

	if (m < n) {
		return 0;
	}

	if (n < m) {
		return solve1(b);
	}

	// resavaj
	cc tmp = b;

	long long sol = 0;

	for (int i = 1; i < m; i++) {
		if (s[i] == '1') {
			cc x = tmp;
			if (s[i - 1] == '1')
				x.c10--;
			else
				x.c00--;
			sol += solve0(x);
		}
		
		if (s[i - 1] == '0' && s[i] == '0') {
			tmp.c00--;
		}
		else if (s[i - 1] == '0' && s[i] == '1') {
			tmp.c01--;
		}
		else if (s[i - 1] == '1' && s[i] == '0') {
			tmp.c10--;
		}
		else {
			tmp.c11--;
		}
	}

	sol += dobar(s, b) ? 1 : 0;
	return sol % MOD;
}

int solveTestcase(string a, string b, cc x) {
	int sol = solve(b, x) - solve(a, x);
	sol += dobar(a, x) ? 1 : 0;
	if (sol < 0)
		sol += MOD;
	else if (sol >= MOD)
		sol -= MOD;

	return sol;
}

string int2binstr(int x) {
	string s;
	while (x) {
		s += (char)((x & 1) + 48);
		x >>= 1;
	}

	reverse(s.begin(), s.end());
	return s;
}

bool bincmp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	return a <= b;
}

int solveBruteForce(string a, string b, cc x) {
	int sol = 0;
	for (int i = 1;; i++) {
		string s = int2binstr(i);
		if (bincmp(a, s) && bincmp(s, b)) {
			if (dobar(s, x)) {
				sol++;
			}
		}
		else if (!bincmp(s, b)) {
			break;
		}
	}
	return sol;
}

void stressTest() {
	int q = 10000000;
	srand(43414143);
	while (q--) {
		vector<int> x(4);
		for (int& v : x)
			v = rand() % 4;
		string a = int2binstr(rand() % 256 + 1);
		string b = int2binstr(rand() % 256 + 1);
		if (!bincmp(a, b)) {
			swap(a, b);
		}

		cc y = { x[0], x[1], x[2], x[3] };
		
		int sol1 = solveTestcase(a, b, y);
		int sol2 = solveBruteForce(a, b, y);
		
		if (sol1 != sol2) {
			cerr << a << ' ' << b << '\n';
			cerr << x[0] << '\n';
			cerr << x[1] << '\n';
			cerr << x[2] << '\n';
			cerr << x[3] << '\n';
			cerr << sol1 << ' ' << sol2 << '\n';
			return;
		}

		if (q % 1000 == 0) {
			cerr << q << '\n';
		}
	}
}

int main() {

	f[0] = finv[0] = 1;
	for (int i = 1; i < 200005; i++) {
		f[i] = f[i - 1] * 1ll * i % MOD;
		finv[i] = pw(f[i], MOD - 2);
	}

	// stressTest();

	// solve("10011111", { 2, 1, 2, 2 });

	string a, b;
	cc x;
	cin >> a >> b;
	cin >> x.c00 >> x.c01 >> x.c10 >> x.c11;
	
	cout << solveTestcase(a, b, x) << '\n';

	// system("pause");
}