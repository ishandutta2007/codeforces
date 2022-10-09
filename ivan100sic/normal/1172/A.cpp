#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct problem {
	int n;
	vector<int> a, b;

	void ucitaj() {
		cin >> n;
		a.resize(n);
		b.resize(n);
		for (int& x : a)
			cin >> x;
		for (int& x : b)
			cin >> x;
	}

	void probaj_polureseno() {
		int x = b[n-1];
		for (int i=1; i<=x; i++) {
			if (b[n+i-x-1] != i) {
				return;
			}
		}
		// ok dobro je, igraj greedy
		vector<int> cnt(n+1, 0);
		for (int x : a)
			cnt[x]++;

		int movs = 0, j = 0;
		while (x != n) {
			movs++;
			x++;
			if (cnt[x] == 0)
				return;
			cnt[x]--;
			cnt[b[j++]]++;
		}
		cout << movs << '\n';
		exit(0);
	}

	void probaj_iznova() {
		vector<int> pos(n+1, 0);
		for (int i=0; i<n; i++) {
			if (b[i] > 0)
				pos[b[i]] = i+1;
		}

		int sol = 0;
		for (int i=1; i<=n; i++)
			sol = max(sol, pos[i] - i + 1);

		cout << sol + n << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	problem p;
	p.ucitaj();
	auto q = p;
	q.probaj_polureseno();
	p.probaj_iznova();
}