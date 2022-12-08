#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	long long int n, k;
	cin >> n >> k;
	vector<long long int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if (k == 0) {
		if (a[0] == 1) cout << -1 << "\n";
		else cout << a[0] - 1 << "\n";
	}
	else {
		if (a[k] == a[k - 1]) cout << -1 << "\n";
		else cout << a[k - 1] << "\n";
	}
	//system("pause");
	return 0;
}