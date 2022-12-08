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

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = -1, r = m;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		vector<int> nn(n);
		if (a[0] + mid >= m || a[0] == 0) nn[0] = 0;
		else nn[0] = a[0];
		bool fl = true;
		for (int i = 1; i < n; i++) {
			if (a[i] < nn[i - 1]) {
				if (a[i] + mid >= nn[i - 1]) {
					nn[i] = nn[i - 1];
				}
				else {
					fl = false;
					break;
				}
			}
			else {
				if (a[i] + mid >= nn[i - 1] + m) {
					nn[i] = nn[i - 1];
				} else{
					nn[i] = a[i];
				}
			}
		}
		/*cout << mid << endl;
		for (int i : nn) cout << i << " ";
		cout << endl;*/
		if (!fl) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << r << endl;
	return 0;
}