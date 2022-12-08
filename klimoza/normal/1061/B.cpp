#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

typedef long long ll;


bool cmp(int x, int y) {
	if (x > y) return true;
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end(), cmp);
	ll tot = 1;
	ll cur = a[0] - 1;
	if (n == 1) {
		cout << 0 << endl;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (a[i] >= cur) {
				tot++;
				cur--;
			}
			else {
				tot += cur - a[i];
				cur = a[i];
				tot++;
				cur--;
			}
		}
		if (cur > 0) tot += cur;
		cout << sum - tot << endl;
	}
	//system("pause");
	return 0;
}