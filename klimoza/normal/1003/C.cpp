#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	cout.precision(15);
	int	n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<double> s(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + k - 1; j < n; j++) {
			ans = max(ans, (s[j + 1] - s[i]) / (j - i + 1));
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}