#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> col(n + 2, 1);
	for (int i = 2; i < n + 2; i++) {
		if (col[i] == 1 && i * 1ll * i < n + 2) {
			for (int j = i * i; j < n + 2; j += i)
				col[j] = max(col[j], col[i] + 1);
		}
	}
	int mx = 0;
	for (int i = 2; i < n + 2; i++)
		if (col[i] > mx)
			mx = col[i];
	cout << mx << '\n';
	for (int i = 2; i < n + 2; i++)
		cout << col[i] << ' ';
	return 0;
}