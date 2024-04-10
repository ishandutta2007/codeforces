#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int mus(string s) {
	map<string, int> mp;
	int n = s.size();
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<=n; j++) {
			string p = s.substr(i, j-i);
			mp[p]++;
		}
	}
	int ml = n;
	for (auto [p, x] : mp) {
		if (x == 1) {
			ml = min(ml, (int)p.size());
		}
	}
	return ml;
}

string brut(int n, int k) {
	for (int i=0; i<(1<<n); i++) {
		string s;
		for (int j=0; j<n; j++)
			s += i & (1 << j) ? '1' : '0';
		reverse(s.begin(), s.end());
		if (mus(s) == k) {
			return s;
		}
	}
	return "impossible\n";
}

string full(int n, int k) {
	if (n == k) {
		return string(n, '0');
	} else if (k <= 2) {
		return string(n-k, '0') + string(k, '1');
	} else if (n >= 3*k-4) {
		string nu = string(k-2, '0');
		return string(n-(2*k-4 + 2), '0') + '1' + nu + '1' + nu;
	} else {
		int period = (n-k) / 2 + 1;
		auto rep = string(period-1, '0') + '1';
		string s;
		for (int i=0; i<n; i++)
			s += rep[i % period];
		return s;
	}

	return "impossible\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;

	cout << full(n, k);
	return 0;

	for (int n=1; n<=20; n++)
		for (int k=n; k>0; k-=2)
			if (brut(n, k) != full(n, k))
				cerr << "Error " << n << ' ' << k << '\n';
	cout << brut(n, k) << '\n';
	cout << full(n, k) << '\n';
}