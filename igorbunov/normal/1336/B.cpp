#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

vector<int> arr1(100000);
vector<int> arr2(100000);
vector<int> arr3(100000);

int n1;
int n2;
int n3;

int val(int ind1, int ind2, int ind3) {
	int ans = 0;
	ans += (arr1[ind1] - arr2[ind2]) * (arr1[ind1] - arr2[ind2]);
	ans += (arr3[ind3] - arr2[ind2]) * (arr3[ind3] - arr2[ind2]);
	ans += (arr1[ind1] - arr3[ind3]) * (arr1[ind1] - arr3[ind3]);
	return ans;
}

int get(int ind1, int ind2) {
	int ans = val(ind1, ind2, 0);
	ans = min(ans, val(ind1, ind2, n3 - 1));
	int l = 0;
	int r = n3 - 1;
	for (int i = 0; i < 30; i++) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		int val1 = val(ind1, ind2, m1);
		int val2 = val(ind1, ind2, m2);
		ans = min(ans, val1);
		ans = min(ans, val2);
		if (val1 < val2) {
			r = m2;
		} else {
			l = m1;
		}
	}
	for (int i = max(0LL, l - 1); i < (min(n3 - 1, r + 1)); i++) {
		ans = min(ans, val(ind1, ind2, i));
	}
	return ans;
}

void solve() {
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
		//arr1[i] = rand() % 100;
	}
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
		//arr2[i] = rand() % 100;
	}
	for (int i = 0; i < n3; i++) {
		cin >> arr3[i];
		//arr3[i] = rand() % 100;
	}
	sort(arr1.begin(), arr1.begin() + n1);
	sort(arr2.begin(), arr2.begin() + n2);
	sort(arr3.begin(), arr3.begin() + n3);
	int ans = val(0, 0, 0);
	int now = 0;
	for (int i = 0; i < n1; i++) {
		int l = 0;
		int r = n2 - 1;
		ans = min(ans, get(i, l));
		ans = min(ans, get(i, r));
		for (int j = 0; j < 30; j++) {
			int m1 = l + (r - l) / 3;
			int m2 = r - (r - l) / 3;
			int val1 = get(i, m1);
			int val2 = get(i, m2);
			ans = min(ans, val1);
			ans = min(ans, val2);
			if (val1 < val2) {
				r = m2;
			} else {
				l = m1;
			}
		}
		for (int j = max(0LL, l - 5); j < (min(n2 - 1, r + 5)); j++) {
			ans = min(ans, get(i, j));
		}
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}