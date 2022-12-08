#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int ind_1 = 0;
	int ind_2 = 0;
	int ans = 0;
	while (ind_1 < n and ind_2 < m) {
		if (a[ind_1] > b[ind_2]) {
			ind_1++;
		}
		else {
			ans++;
			ind_1++;
			ind_2++;
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}