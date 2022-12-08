#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



int main() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ind_l = (lower_bound(a.begin(), a.end(), s) - a.begin());
	int ind_u = (upper_bound(a.begin(), a.end(), s) - a.begin());
	int med = n / 2;
	if (ind_l <= med && ind_u > med) {
		cout << (ind_u - ind_l) * (s - a[med]) << "\n";
	}
	else if (ind_u <= med) {
		long long int count = 0;
		for (int i = ind_u; i <= med; i++) {
			count += (a[i] - s);
		}
		cout << count << "\n";
	}
	else {
		long long int count = 0;
		for (int i = ind_u - 1; i >= med; i--) {
			count += (s - a[i]);
		}
		cout << count << "\n";
	}
	//system("pause");
	return 0;
}