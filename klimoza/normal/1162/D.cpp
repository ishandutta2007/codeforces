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
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int md(int x, int n) {
	if (x == n) return x;
	else return x % n;
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	map<pair<int, int>, char> f;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		a[i] = { t1, t2 };
		f[{t1, t2}] = true;
		f[{t2, t1}] = true;
	}
	bool fl = false;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i != 0) continue;
		bool bl = true;
		for (auto u : a) {
			if (!f[{md(u.first + i, n), md(u.second + i, n)}]) {
				bl = false;
				break;
			}
		}
		if (bl) {
			fl = true;
			break;
		}
		if (i != 1) {
			bl = true;
			for (auto u : a) {
				if (!f[{md(u.first + n/i, n), md(u.second + n/i, n)}]) {
					bl = false;
					break;
				}
			}
			if (bl) {
				fl = true;
				break;
			}
		}
	}
	if (fl) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	//system("pause");
	return 0;
}