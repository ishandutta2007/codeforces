#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define MOD (998244353)

int inv(int v) {
	return v <= 1 ? v : MOD - (long long)inv(MOD % v) * (MOD / v) % MOD;
}

struct mint {
	int v;
	mint() = default;
	mint(long long v) : v((v% MOD + MOD) % MOD) {}

	mint& operator+=(mint a) {
		v = (v + a.v) % MOD;
		return *this;
	}

	mint& operator-=(mint a) {
		v = (v - a.v + MOD) % MOD;
		return *this;
	}

	mint& operator*=(mint a) {
		v = ((long long)v * a.v) % MOD;
		return *this;
	}

	mint& operator/=(mint a) {
		v = ((long long)v * inv(a.v)) % MOD;
		return *this;
	}

	friend mint operator+(mint a, mint b) {
		return mint(a.v + b.v);
	}

	friend mint operator-(mint a, mint b) {
		return mint(a.v - b.v);
	}

	friend mint operator*(mint a, mint b) {
		return mint((long long)a.v * b.v);
	}

	friend mint operator/(mint a, mint b) {
		return mint((long long)a.v * inv(b.v));
	}
};


int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<mint> f(n + 1);
	vector<mint> g(n + 1);
	vector<mint> h(n + 1);

	f[0] = 1;
	g[0] = 1;
	h[0] = 1;

	mint s = 0;
	vector<int> vals;
	vals.push_back(-1);

	auto ff = [&](int l, int r) {
		mint s = h[r];
		if (l >= 0) {
			s -= h[l];
		}
		return s * a[r];
	};

	for (int i = 0; i < n; ++i) {
		while (vals.back() >= 0 && a[i] <= a[vals.back()]) {
			s -= ff(vals[vals.size() - 2], vals.back());
			vals.pop_back();
		}
		vals.push_back(i);
		s += ff(vals[vals.size() - 2], vals.back());

		f[i + 1] = s * (i % 2 ? -1 : +1);
		g[i + 1] = s * (-1);
		h[i + 1] = h[i] + g[i + 1];
	}
	printf("%d\n", f[n].v);
	return 0;
}