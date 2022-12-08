#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		cin >> a[i].second;
	}
	int m;
	cin >> m;
	vector<pair<int, int>> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i].first;
		cin >> b[i].second;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int l = 0;
	int r = 0;
	long long int sum = 0;
	while (l < n or r < m) {
		if (l == n) {
			sum += b[r].second;
			r++;
		}
		else if (r == m) {
			sum += a[l].second;
			l++;
		}
		else {
			if (a[l].first == b[r].first) {
				sum += max(a[l].second, b[r].second);
				l++;
				r++;
			}
			else if(a[l].first > b[r].first) {
				sum += b[r].second;
				r++;
			}
			else {
				sum += a[l].second;
				l++;
			}
		}
	}
	cout << sum << "\n";
	//system("pause");
	return 0;
}