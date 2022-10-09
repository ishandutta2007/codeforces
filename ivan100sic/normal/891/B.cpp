#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> a;
int b[1005];
int rankkk[1005];
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.push_back({x, i});
	}
	sort(a.begin(), a.end());

	for (int i=0; i<n; i++) {
		rankkk[a[i].second] = i;
	}

	for (int i=0; i<n; i++) {
		int r = rankkk[i];
		b[i] = a[(r + 1) % n].first;
	}

	for (int i=0; i<n; i++) {
		cout << b[i] << ' ';
	}
}