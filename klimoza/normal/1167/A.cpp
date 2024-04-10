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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string st;
		cin >> st;
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (st[i] == '8') {
				ind = i;
				break;
			}
		}
		if (ind == -1) {
			cout << "NO\n";
		}
		else {
			n -= ind;
			if (n >= 11) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	//system("pause");
	return 0;
}