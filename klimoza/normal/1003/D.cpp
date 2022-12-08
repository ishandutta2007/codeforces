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
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	map<int, int> f;
	int ind = 1;
	for (int i = 0; i < 31; i++) {
		f[ind] = i;
		ind *= 2;
	}
	vector<int> cnt(31);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cnt[f[t]]++;
	}
	int d;
	vector<int> cur(31);
	for (int i = 0; i < q; i++) {
		cur.clear(); cur.resize(31); copy(cnt.begin(), cnt.end(), cur.begin());
		cin >> d;
		bool fl = true;
		int r = 0;
		for (int j = 30; j >= 0; j--) {
			if (d < (1 << j)) continue;
			int t = (d / (1 << j));
			t = min(t, cur[j]);
			d -= t * (1 << j);
			r += t;
			cur[j] -= t;
		}
		if (!d) {
			cout << r << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	//system("pause");
	return 0;
}