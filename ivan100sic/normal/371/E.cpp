// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct stanica {
	int x, id;

	template<class T>
	auto operator< (const T& b) const {
		return x < b.x;
	}
};

int n, k;
stanica a[300005];
ull d[300005];
ull z[600005];

void dod(ull c, ull e) {
	for (int i=0; i<n-1; i++)
		z[i+e] += c * d[i];
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x, a[i].id = i+1;

	sort(a, a+n);

	cin >> k;

	for (int i=0; i<n-1; i++)
		d[i] = a[i+1].x - a[i].x;

	dod(k-1, 0);
	dod(-1-k, 1);
	dod(k+1, k);
	dod(1-k, k+1);

	// triput ps
	for (int i=0; i<3; i++) {
		for (int j=1; j<600005; j++) {
			z[j] += z[j-1];
		}
	}

	ull u = ~0;
	int s = 0;

	for (int i=k-2; i<n-1; i++) {
		if (z[i] < u) {
			u = z[i];
			s = i-k+2;
		}
	}

	for (int j=s; j<s+k; j++) {
		cout << a[j].id << " \n"[j == s+k-1];
	}
}