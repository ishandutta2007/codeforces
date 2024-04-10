#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<long long int> prefix(n);
	cin >> a[0];
	prefix[0] = a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}
	vector<long long int> suffix(n);
	suffix[0] = a[n - 1];
	for (int i = 1; i < n; i++) {
		suffix[i] = suffix[i - 1] + a[n - 1 - i];
	}
	int l = 0;
	int r = 0;
	long long int maxi = 0;
	while (l + r + 2 <= n) {
		if (prefix[l] == suffix[r]) {
			maxi = prefix[l];
			l++;
			r++;
		}
		else if (prefix[l] < suffix[r]) {
			l++;
		}
		else {
			r++;
		}
	}
	cout << maxi << "\n";
	//system("pause");
	return 0;
}