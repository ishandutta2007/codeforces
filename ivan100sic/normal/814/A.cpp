#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	a.resize(n);
	for (int& x : a) {
		cin >> x;
	}
	b.resize(m);
	for (int& x : b) {
		cin >> x;
	}

	sort(b.begin(), b.end(), greater<int>());

	auto it = b.begin();

	for (int& x : a) {
		if (x == 0) {
			x = *it;
			++it;
		}
	}

	bool notinc = false;

	for (int i=1; i<(int)a.size(); i++) {
		if (a[i-1] >= a[i]) {
			notinc = true;
			break;
		}
	}

	cout << (notinc ? "Yes" : "No");

}