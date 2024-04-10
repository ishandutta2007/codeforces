#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

string ime(int x) {
	string s(1, (char)(x%26 + 'A'));
	x /= 26;
	while (x > 0) {
		s += (char)(x%26 + 'a');
		x /= 26;
	}
	return s;
}

string a[105], b[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k, c = 0;
	cin >> n >> k;
	for (int i=1; i<=n-k+1; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		b[i] = ime(i);
	}

	for (int i=1; i<=n-k+1; i++) {
		if (a[i] == "NO") {
			b[i+k-1] = b[i];
		}
	}

	for (int i=1; i<=n; i++) {
		cout << b[i] << ' ';
	}

}