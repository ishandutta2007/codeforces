#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int maxi = 0;
	int sum = 0;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum += t;
		maxi = max(maxi, t);
	}
	sum += m;
	int k = sum / n;
	if (sum % n != 0) {
		k++;
	}
	cout << max(maxi, k) << " " << maxi + m << "\n";
	//system("pause");
	return 0;
}