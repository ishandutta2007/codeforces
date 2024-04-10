#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a, b;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> b >> a;
	vector<int> sol;
	for (int i=0; i<n; i++) {
		char x = a[i];
		auto it = find(b.begin()+i, b.end(), x);
		if (it == b.end()) {
			cout << -1;
			return 0;
		}
		int j = it - b.begin();
		for (int k=j-1; k>=i; k--) {
			swap(b[k], b[k+1]);
			sol.push_back(k+1);
		}
	}
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}