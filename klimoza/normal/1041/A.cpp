#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		l += a[i + 1] - a[i] - 1;
	}
	cout << l << "\n";
	//system("pause");
	return 0;
}