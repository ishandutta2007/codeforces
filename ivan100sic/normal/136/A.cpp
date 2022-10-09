#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	vector<int> b;

	cin >> n;

	b.resize(n+1);
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		b[x] = i;
	}

	for (int i=1; i<=n; i++) {
		cout << b[i] << ' ';
	}
}