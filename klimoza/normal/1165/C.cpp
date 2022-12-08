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

	int n;
	cin >> n;
	string st;
	cin >> st;
	vector<char> good1(n, true);
	bool fl = false;
	int cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (fl && st[i] == st[i - 1]) {
			good1[i] = false;
			cnt1++;
		}
		else if (fl) {
			fl = false;
		}
		else if ((i - cnt1) % 2 && st[i] == st[i - 1]) {
			fl = true;
			good1[i] = false;
			cnt1++;
		}
	}
	if ((n - cnt1) % 2) {
		for (int i = n - 1; i >= 0; i--) {
			if (good1[i]) {
				good1[i] = false;
				break;
			}
		}
		cnt1++;
	}
	vector<char> good2(n, true);
	fl = false;
	int cnt2 = 1;
	good2[0] = false;
	for (int i = 2; i < n; i++) {
		if (fl && st[i] == st[i - 1]) {
			good2[i] = false;
			cnt2++;
		}
		else if (fl) {
			fl = false;
		}
		else if ((i - cnt2) % 2 && st[i] == st[i - 1]) {
			fl = true;
			good2[i] = false;
			cnt2++;
		}
	}
	if ((n - cnt2) % 2) {
		for (int i = n - 1; i >= 0; i--) {
			if (good2[i]) {
				good2[i] = false;
				break;
			}
		}
		cnt2++;
	}
	if (cnt1 < cnt2) {
		cout << cnt1 << endl;
		for (int i = 0; i < n; i++) {
			if (good1[i]) cout << st[i];
		}
	}
	else {
		cout << cnt2 << endl;
		for (int i = 0; i < n; i++) {
			if (good2[i]) cout << st[i];
		}
	}
	cout << endl;
	//system("pause");
	return 0;
}