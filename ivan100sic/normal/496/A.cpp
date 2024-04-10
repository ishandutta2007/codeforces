#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int diff(vector<int> a) {
	int d = 0;
	for (int i=0; i<(int)a.size()-1; i++) {
		d = max(d, a[i+1] - a[i]);
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];

	int sol = 1123123123;
	for (int i=1; i<n-1; i++) {
		auto b = a;
		b.erase(b.begin() + i);
		sol = min(sol, diff(b));
	}	
	cout << sol << '\n';
}