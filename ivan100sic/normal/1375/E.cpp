// Retired?
// #define XD

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[1005];

void gen() {
	n = 32;
	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution uid(1, 4);
	for (int i=0; i<n; i++) {
		a[i] = uid(eng);
	}
}

void rd() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
}

struct inv {
	int j, key;

	bool operator< (const inv& b) const {
		return pair(key, -j) < pair(b.key, -b.j);
	}
};

vector<inv> e[1005];

void svop(int i, int j) {
	swap(a[i], a[j]);
	cout << i+1 << ' ' << j+1 << '\n';
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

#ifdef XD
	gen();
#else
	rd();
#endif

	int invc = 0;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (a[i] > a[j]) {
				invc++;
				e[i].push_back({j, -a[j]});
			}
		}
		sort(begin(e[i]), end(e[i]));
	}

	cout << invc << '\n';

	for (int i=0; i<n; i++) {
		for (auto v : e[i]) {
			svop(i, v.j);
		}
	}

#ifdef XD
	for (int i=0; i<n; i++) {
		cout << a[i] << " \n"[i == n-1];
	}
#endif

}