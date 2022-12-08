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
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(2 * n);
	int m = 2 * n;
	int b = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		b += a[i];
	}
	int f = 0;
	vector<int> t1(n), t2(n);
	for (int i = 0; i < n; i++) {
		f += a[i];
		t1[i] = a[i];
		t2[i] = a[i + n];
	}
	//cout << "flex\n";
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	if (2 * f != b) {
		for (int i : a) cout << i << " ";
		cout << endl;
	}
	else {
		if (t1[0] == t1[n - 1] && t1[n - 1] == t2[0] && t2[0] == t2[n - 1]) {
			cout << -1 << endl;
		}
		else {
			if (t1[0] != t2[0]) swap(t1[0], t2[0]);
			else if (t1[0] != t2[n - 1]) swap(t1[0], t2[n - 1]);
			else if (t1[n - 1] != t2[0]) swap(t1[n - 1], t2[0]);
			else swap(t1[n - 1], t2[n - 1]);
			for (int i : t1) cout << i << " ";
			for (int i : t2) cout << i << " ";
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}