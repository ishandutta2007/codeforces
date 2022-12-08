#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 998244353;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> k >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int f4 = k;
	int f2 = 2 * k;
	for (int i = 0; i < n; i++) {
		while (a[i] >= 4 && f4) {
			f4--;
			a[i] -= 4;
		}
		while (a[i] >= 4 && f2 >= 2) {
			a[i] -= 4;
			f2 -= 2;
		}
		if (a[i] >= 4) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		//cout << a[i] << " " << f4 << " " << f2 << endl;
		if (a[i] >= 3 && f4) {
			f4--;
			a[i] -= 3;
		}
		if (a[i] >= 3 && f2 >= 2) {
			f2 -= 2;
			a[i] -= 3;
		}
		if (a[i] >= 3) {
			cout << "NO\n";
			return 0;
		}
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	while (!a.empty() && a.back() == 0) a.pop_back();
	int l = 0, r = a.size() - 1;
	while (f4 && r - l > 0 && a[l] == 2 && a[r] == 1) {
		//cout << f4 << " " << l << " " << r << endl;
		f4--;
		a[r] -= 1;
		a[l] -= 2;
		r--;
		l++;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	while (!a.empty() && a.back() == 0) a.pop_back();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 2) {
			if (f2) {
				f2--;
				a[i] -= 2;
			}
			else if (f4) {
				if (f4 >= 2 && i < a.size() - 2) {
					f4 -= 2;
					a[i] -= 2; a[i + 1] -= 2; a[i + 2] -= 2;
					i += 2;
				}
				else {
					f4--;
					a[i] -= 2;
				}
			}
			else {
				cout << "NO\n";
				//system("pause");
				return 0;
			}
		}
		else {
			if (f4) {
				if (i != a.size() - 1) {
					i++;
					f4--;
					a[i]--;
					a[i + 1]--;
				}
				else {
					f4--;
					a[i]--;
				}
			}
			else if (f2) {
				f2--;
				a[i]--;
			}
			else {
				cout << "NO\n";
				//system("pause");
				return 0;
			}
		}
	}
	cout << "YES\n";
	//system("pause");
	return 0;
}