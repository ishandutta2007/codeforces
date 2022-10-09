#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

vector<int> primes;
int f[10005];

void sito() {
	for (int i = 2; i <= 10000; i++) {
		if (f[i] == 0) {
			primes.push_back(i);
			for (int j = i * i; j <= 10000; j += i) {
				f[j] = 1;
			}
		}
	}
}

int sqfaktor(int n) {
	if (n == 0) {
		return 0;
	}

	int z = 1;
	if (n < 0) {
		n *= -1;
		z = -1;
	}

	for (int p : primes) {
		if (n % p == 0) {
			int c = 0;
			while (n % p == 0) {
				n /= p;
				c++;
			}
			if (c & 1) {
				z *= p;
			}
		}
	}

	if (n > 1)
		z *= n;

	return z;
}

int a[5005];
int b[5005], n;
int c[5005];
int sol[5005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	sito();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = sqfaktor(a[i]);
	}

	map<int, int> mp;
	// kompresuj b
	for (int i = 0; i < n; i++) {
		if (b[i] != 0) {
			mp[b[i]] = 0;
		}
	}

	int cnt = 0;
	for (auto& p : mp) {
		p.second = ++cnt;
	}

	for (int i = 0; i < n; i++) {
		b[i] = mp[b[i]];
	}

	for (int i = 0; i < n; i++) {
		int zz = 0;
		fill(c, c + n + 3, 0);
		for (int j = i; j < n; j++) {
			if (b[j] != 0) {
				c[b[j]]++;
				if (c[b[j]] == 1) {
					zz++;
				}
			}
			int x = zz ? zz : 1;
			sol[x]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}

int main() {
	solve();
	// system("pause");
}