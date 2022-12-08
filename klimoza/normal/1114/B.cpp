#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	vector<bool> used(n);
	sort(a.begin(), a.end());
	ll su = 0;
	for (int i = n - 1; i >= n - (m * k); i--) {
		used[a[i].second] = true;
		su += a[i].first;
	}
	cout << su << endl;
	int cnt = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			cnt++;
			count++;
		}
		if (cnt == m) {
			cnt = 0;
			if(count != m * k)
				cout << i + 1 << " ";
		}
	}
	cout << endl;
	//system("pause");
	return 0;
}