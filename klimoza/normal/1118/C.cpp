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
	
	int n;
	cin >> n;
	int t;
	vector<vector<int>> ans(n, vector<int>(n));
	vector<int> cnt(1001);
	for (int i = 0; i < n * n; i++) {
		cin >> t;
		cnt[t]++;
	}
	int normx = 0, normy = 0;
	int verx = 0, gorx = 0;
	bool centre = false;
	for (int i = 1; i <= 1000; i++) {
		if (!cnt[i]) continue;
		if (cnt[i] % 2 == 1) {
			if (n % 2 == 0 || centre) {
				cout << "NO\n";
				return 0;
			}
			else {
				ans[n / 2][n / 2] = i;
				cnt[i]--;
				centre = true;
			}
		}
		if (cnt[i] % 4 == 2) {
			if (n % 2 == 0 || (verx >= (n / 2) && gorx >= (n / 2))) {
				cout << "NO\n";
				return 0;
			}
			else if (verx != (n / 2)) {
				ans[verx][n / 2] = i;
				ans[n - 1 - verx][n / 2] = i;
				verx++;
			}
			else {
				ans[n / 2][gorx] = i;
				ans[n / 2][n - 1 - gorx] = i;
				gorx++;
			}
			//cout << verx << " " << gorx << endl;
			cnt[i] -= 2;
		}
		//cout << cnt[i] << " " << i << " " << normx << " " << normy << endl;
		while (cnt[i]) {
			if (normx >= n / 2) {
				normx = 0;
				normy++;
			}
			if (normy >= n / 2) {
				break;
			}
			ans[normy][normx] = i;
			ans[normy][n - 1 - normx] = i;
			ans[n - 1 - normy][normx] = i;
			ans[n - 1 - normy][n - 1 - normx] = i;
			cnt[i] -= 4;
			normx++;
		}
		while(cnt[i]) {
			if (verx >= (n / 2) && gorx >= (n / 2)) {
				cout << "NO\n";
				return 0;
			}
			else if (verx != (n / 2)) {
				ans[verx][n / 2] = i;
				ans[n - 1 - verx][n / 2] = i;
				verx++;
			}
			else {
				ans[n / 2][gorx] = i;
				ans[n / 2][n - 1 - gorx] = i;
				gorx++;
			}
			cnt[i] -= 2;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}