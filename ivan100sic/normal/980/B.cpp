#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	if (k % 2 == 0) {
		cout << "YES\n";
		cout << string(n, '.') << '\n';
		cout << '.' << string(k / 2, '#') << string(n - 1 - k / 2, '.') << '\n';
		cout << '.' << string(k / 2, '#') << string(n - 1 - k / 2, '.') << '\n';
		cout << string(n, '.') << '\n';
		return;
	}

	if (k == 1) {
		cout << "YES\n";
		cout << string(n, '.') << '\n';
		cout << string(n / 2, '.') << '#' << string(n / 2, '.') << '\n';
		cout << string(n, '.') << '\n';
		cout << string(n, '.') << '\n';
		return;
	}

	if (k == 3) {
		cout << "YES\n";
		cout << string(n, '.') << '\n';
		cout << string(n / 2 - 1, '.') << "###" << string(n / 2 - 1, '.') << '\n';
		cout << string(n, '.') << '\n';
		cout << string(n, '.') << '\n';
		return;
	}

	{
		cout << "YES\n";
		cout << string(n, '.') << '\n';
		cout << ".#.#" << string(k / 2 - 2, '#') << string(n - 2 - k / 2, '.') << '\n';
		cout << ".###" << string(k / 2 - 2, '#') << string(n - 2 - k / 2, '.') << '\n';
		cout << string(n, '.') << '\n';
		return;
	}
}

int main() {
	solve();
	// system("pause");
}