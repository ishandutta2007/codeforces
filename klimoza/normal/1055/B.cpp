#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	ll n, m, l;
	cin >> n >> m >> l;
	vector<ll> a(n);
	ll ans = 0;
	bool fl = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= l && fl) {
			ans++;
			fl = false;
		} 
		if (a[i] > l) fl = true;
	}
	if (fl) ans++;
	int t1, t2, t3;
	for (int i = 0; i < m; i++) {
		cin >> t1;
		if (t1 == 0) {
			cout << ans << "\n";
		}
		else {
			cin >> t2 >> t3;
			t2--;
			if (a[t2] > l) a[t2] = l + 1;
			if (n == 1) {
				if (a[0] > l || a[0] + t3 <= l) {
					if (a[0] <= l) a[0] += t3;
					continue;
				}
				else {
					a[0] += t3;
					ans++;
				}
			}
			else {
				if (a[t2] > l || a[t2] + t3 <= l) {
					if (a[t2] <= l) a[t2] += t3;
					continue;
				}
				if (t2 == 0) {
					if (a[1] > l) {
						a[0] += t3;
						continue;
					}
					else {
						a[0] += t3;
						ans++;
					}
				}
				else if (t2 == n - 1) {
					if (a[n - 2] > l) {
						a[n - 1] += t3;
						continue;
					}
					else {
						a[n - 1] += t3;
						ans++;
					}
				}
				else {
					if (a[t2 - 1] > l && a[t2 + 1] > l) {
						a[t2] += t3;
						ans--;
					}
					else if (a[t2 - 1] <= l && a[t2 + 1] <= l) {
						a[t2] += t3;
						ans++;
					}
					else {
						a[t2] += t3;
					}
				}
			}
		}
	}
	//system("pause");  
	return 0;
}