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
ll mod = 1e8;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int m, s;
	cin >> m >> s;
	if ((s == 0 && m > 1) || (m * 9 < s)) {
		cout << -1 << " " << -1 << endl;
	}
	else {
		vector<int> mi(m);
		int cur = s;
		for (int i = m - 1; i >= 0; i--) {
			if (i == 0) mi[i] = cur;
			else if (cur > 9) {
				mi[i] = 9;
				cur -= 9;
			}
			else if (cur == 1) {
				continue;
			}
			else {
				mi[i] = cur - 1;
				cur = 1;
			}
		}
		vector<int> ma(m);
		cur = s;
		for (int i = 0; i < m; i++) {
			if (cur >= 9) {
				ma[i] = 9;
				cur -= 9;
			}
			else {
				ma[i] = cur;
				cur = 0;
			}
		}
		for (int i : mi) cout << i;
		cout << " ";
		for (int i : ma) cout << i;
		cout << endl;
	}
	//system("pause");
	return 0;
}