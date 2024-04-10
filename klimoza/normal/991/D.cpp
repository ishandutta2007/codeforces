#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	vector<pair<int, int>> a;
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].first = 0;
		a[i].second = 0;
		if (s1[i] == 'X') {
			a[i].first++;
		}
		if (s2[i] == 'X') {
			a[i].second++;
		}
	}
	int count = 0;
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum = a[i].first + a[i].second + a[i + 1].first + a[i + 1].second;
		if (sum == 0) {
			a[i].first = 1;
			a[i].second = 1;
			a[i + 1].first = 1;
			count++;
		}
		else if (sum == 1) {
			a[i].first = 1;
			a[i].second = 1;
			a[i + 1].first = 1;
			a[i + 1].second = 1;
			count++;
		}
	}
	cout << count << "\n";
	//system("pause");
	return 0;
}