#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, c;
vector<int> a[500005];
int z[1000005];

void ans(int x) {
	cout << x << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c;
	for (int i=0; i<n; i++) {
		int l;
		cin >> l;
		a[i].resize(l);
		for (int& x : a[i])
			cin >> x;
	}

	int ev = 0;

	for (int i=1; i<n; i++) {
		auto& last = a[i-1];
		auto& curr = a[i];
		int diff = -1;
		for (int j=0; j<(int)min(last.size(), curr.size()); j++) {
			if (last[j] != curr[j]) {
				diff = j;
				break;
			}
		}
		if (diff == -1) {
			if (last.size() > curr.size())
				ans(-1);
		} else {
			int x = last[diff];
			int y = curr[diff];
			ev++;

			if (x < y) {
				z[0]++;
				z[c+1-y]--;
				z[c+1-x]++;
				// ne treba --
			} else {
				z[c+1-x]++;
				z[c+1-y]--;
			}
		}
	}

	for (int i=0; i<c; i++) {
		z[i+1] += z[i];
		if (z[i] == ev)
			ans(i);
	}
	ans(-1);
}