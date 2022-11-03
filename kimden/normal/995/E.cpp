#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int p;
inline int add(int x, int y) {
	int z = x + y;
	if (z >= p) {
		z -= p;
	}
	return z;
}
inline int sub(int x, int y) {
	int z = x + p - y;
	if (z >= p) {
		z -= p;
	}
	return z;
}
inline int mul(int x, int y) {
	return (x * (ll)y) % p;
}
inline int binpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}
inline int inv(int x) {
	return binpow(x, p - 2);
}

const int SQ = sqrt(1e9 + 1551);

mt19937 mt(18183636);
uniform_int_distribution<int> uid;

string solve(int x) {
	for (int i = 1; i <= min(p - 1, 10000000); ++i) {
		int j;
		if (p <= 10000000) {
			j = i;
		} else {
			j = uid(mt);
		}
		int num = mul(x, j);
		int denom = j;
		string s;
		while (s.length() < 100 && num != 0) {
			if (num >= denom) {
				num -= denom;
				s.push_back(1);
			} else {
				swap(num, denom);
				s.push_back(2);
			}
		}
		// string t = s;
		// for (char& c: t) c += '1';
		// cout << i << " " << num << " " << denom << " " << t << endl;
		if (num == 0) {
			return s;
		}
	}
	throw;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int s, f;
	cin >> s >> f >> p;
	uid = uniform_int_distribution<int>(1, p - 1);
	string a = solve(s);
	string b = solve(f);
	while (!b.empty()) {
		a.push_back(min(2, b.back() ^ 1));
		b.pop_back();
	}
	for (char& c: a) {
		c += '1';
	}
	cout << a.length() << "\n";
	for (int i = 0; i < a.length(); ++i) {
		if (i) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << "\n";
}