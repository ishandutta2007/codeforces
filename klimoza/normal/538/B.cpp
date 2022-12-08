#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 998244353;

int pw(int x, int p) {
	if (p <= 0) return 1;
	return pw(x, p - 1) * x;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> po(7);
	int h = 1;
	vector<int> ans;
	for (int i = 0; i < 7; i++) {
		po[i] = (n % (10 * h)) / h;
		h *= 10;
	}
	bool fl = true;
	while (fl) {
		int cur = 0;
		fl = false;
		for (int i = 0; i < 7; i++) {
			if (po[i]) {
				fl = true;
				po[i]--;
				cur += pw(10, i);
			}
		}
		if (cur) ans.push_back(cur);
	}
	cout << ans.size() << endl;
	for (int i : ans) cout << i << " ";
	//system("pause");
	return 0;
}