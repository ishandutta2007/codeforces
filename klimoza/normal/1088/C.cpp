#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur = 0;
	cout << n + 1 << endl;
	for (int i = n - 1; i >= 0; i--) {
		if (((a[i] + cur) % n) <= i) {
			cout << "1 " << i + 1 << " " << i - (a[i] + cur) % n << endl;
			cur += i - (a[i] + cur) % n;
		}
		else {
			cout << "1 " << i + 1 << " " << i + n - (a[i] + cur) % n << endl;
			cur += i + n - (a[i] + cur) % n;
		}
	}
	cout << "2 " << n << " " << n << endl;
	//system("pause");
	return 0;
}