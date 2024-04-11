#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int cnt = 0;
	int l = 0, r = 0;
	while (l < n && r < m) {
		if (a[l] == b[r]) {
			cnt++;
			l++;
			r++;
		}
		else {
			if (a[l] > b[r])
				r++;
			else
				l++;
		}
	}
	l = n, r = m;
	int f = cnt;
	int i = 0;
	while (true) {
		if (cnt) {
			cnt--;
			l--;
			r--;
		}
		else {
			if (i == 0)
				l--;
			else
				r--;
		}
		i = (i + 1) % 2;
		if (l == 0 && i == 0) {
			cout << "NO";
			return 0;
		}
		if (r == 0 && i == 1) {
			cout << "YES";
			return 0;
		}
	}
	return 0;
}