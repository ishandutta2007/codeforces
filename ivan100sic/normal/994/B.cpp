#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int p[100005], c[100005], a[100005];
ll sol[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> p[i];
	for (int i=0; i<n; i++)
		cin >> c[i];

	iota(a, a+n, 0);
	sort(a, a+n, [&](int x, int y) {
		return p[x] < p[y];
	});
	multiset<int> pq;
	for (int i=0; i<n; i++) {
		int x = a[i];
		sol[x] += c[x];
		int l = min(i, k);
		auto it = pq.end();
		while (l--) {
			--it;
			sol[x] += *it;
		}
		pq.insert(c[x]);
	}
	for (int i=0; i<n; i++)
		cout << sol[i] << " \n"[i == n-1];
}