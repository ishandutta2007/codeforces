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
	int bal = 0;
	int maxi = 1;
	for (int i = 0; i < n; i++) {
		if (st[i] == '(') {
			bal++;
			maxi = max(maxi, bal);
		}
		else {
			bal--;
		}
	}
	int f = (maxi + 1) / 2;
	bal = 0;
	for (int i = 0; i < n; i++) {
		if (st[i] == '(') {
			bal++;
			if (bal <= f) cout << "0";
			else cout << "1";
		}
		else {
			if (bal <= f) cout << "0";
			else cout << "1";
			bal--;
		}
	}
	cout << endl;
	//system("pause");
	return 0;
}