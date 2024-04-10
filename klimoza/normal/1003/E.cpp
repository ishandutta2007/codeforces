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

int n, k;
int cur;
vector<pair<int, int>> ans;

void dfs(int p, int l) {
	if (cur == n + 1 || l == 0) {
		return;
	}
	ans[cur - 2] = { p, cur };
	//cout << p << " " << l << " flex " << cur << endl;
	int t = cur;
	cur++;
	if (l == 1) return;
	int cnt = k - 1;
	while(cnt && cur <= n){
		//cout << cur << " " << cnt << " " << n << endl;
		dfs(t, l - 1);
		cnt--;
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int d;
	cin >> n >> d >> k;
	ans.resize(n - 1);
	if (d >= n) {
		cout << "NO\n";
	}
	else {
		cur = d + 2;
		for (int i = 2; i <= d + 1; i++) {
			ans[i - 2] = { i - 1, i };
		}
		for (int i = 2; i <= d; i++) {
			if (k == 1) {
				cout << "NO\n";
				return 0;
			}
			if (cur == n + 1) break;
			int cnt = k - 2;
			while (cnt && cur <= n) {
				dfs(i, min(i - 1, d + 1 - i));
				cnt--;
			}
		}
		if (cur <= n) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (auto i : ans) {
				cout << i.first << " " << i.second << endl;;
			}
		}
	}
	//system("pause");
	return 0;
}