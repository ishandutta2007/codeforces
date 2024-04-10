#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii query(vector<int> &x) {
	cout << "? ";
	for (auto num : x) cout << num << ' ';
	cout << '\n';
	fflush(stdout);

	pii ret;
	cin >> ret.va >> ret.vb;
	return ret;
}

int N, K;
int main() {
	cin >> N >> K;
	vector<int> v; v.clear();
	for (int i=1; i<=K; i++) v.push_back(i);

	pii a = query(v);
	int p = a.va, val = a.vb;

	v.clear();
	for (int i=1; i<=K+1; i++) {
		if (i!=p) v.push_back(i);
	}
	pii b = query(v);

	int piv = K+1, pivtype;
	if (b.vb > val) {
		pivtype = 1;
	}
	else pivtype = 0;

	if (pivtype) {
		int ans = 0;
		for (int i=1; i<=K; i++) {
			if (i==p) continue;

			v.clear();
			for (int j=1; j<=K; j++) {
				if (i!=j) v.push_back(j);
			}
			v.push_back(piv);

			pii tmp = query(v);
			if (tmp.vb > val) {
				++ans;
			}
		}

		cout << "! " << ans+1 << '\n';
	}
	else {
		int ans = 0;
		for (int i=1; i<=K; i++) {
			if (i==p) continue;

			v.clear();
			for (int j=1; j<=K; j++) {
				if (i!=j) v.push_back(j);
			}
			v.push_back(piv);

			pii tmp = query(v);
			if (tmp.vb == val) ++ans;
		}

		cout << "! " << ans+1 << '\n';
	}
	exit(0);
}