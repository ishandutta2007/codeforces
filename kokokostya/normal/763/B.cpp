#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 12;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a += INF, b += INF;
		cout << (a % 2) + (b % 2) * 2 + 1 << '\n';
	}
	return 0;
}