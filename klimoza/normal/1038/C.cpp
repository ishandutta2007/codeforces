#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(int x, int y) {
	if (x > y) return true;
	return false;
}


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	int l = 0;
	int r = 0;
	long long int ans = 0;
	int xod = 1;
	while (l != n || r != n) {
		//cout << ans << "\n";
		if (xod == 1) {
			if (l == n) {
				r++;
			}
			else if (r == n) {
				ans += a[l];
				l++;
			}
			else if(a[l] > b[r]){
				ans += a[l];
				l++;
			}
			else {
				r++;
			}
		}
		else {
			if (r == n) {
				l++;
			}
			else if (l == n) {
				ans -= b[r];
				r++;
			}
			else if (b[r] > a[l]) {
				ans -= b[r];
				r++;
			}
			else {
				l++;
			}
		}
		xod *= -1;
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}