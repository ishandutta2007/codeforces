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
ll mod = 1e9 + 7;

void swp(int a, int b, vector<int> &p, vector<int> &rev, vector<pair<int, int>> &ans) {
	int t = p[a];
	p[a] = p[b];
	rev[p[a]] = a;
	p[b] = t;
	rev[t] = b;
	ans.push_back({ a, b });
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
		rev[p[i]] = i;
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		//cout << i << " " << rev[i] << endl;
		if (i == p[i]) continue;
		if (2 * (rev[i] - i) >= n) {
			swp(rev[i], i,p, rev, ans);
		}
		else if (2 * (n - 1 - rev[i]) >= n && (2 * (n - 1 - i)) >= n) {
			swp(rev[i], n - 1, p, rev, ans);
			swp(n - 1, i, p, rev, ans);
		}
		else if (2 * (rev[i]) >= n && (2 * i >= n)) {
			int t = rev[i];
			swp(rev[i], 0, p, rev, ans);
			swp(i, 0, p, rev, ans);
			swp(t, 0, p, rev, ans);
		}
		else if(rev[i]>= n / 2){
			int t = rev[i];
			swp(rev[i], 0, p, rev, ans);
			swp(0, n - 1, p, rev, ans);
			swp(n - 1, i, p, rev, ans);
			swp(0, t, p, rev, ans);
		}
		/*else {
			int t = rev[i];
			swp(rev[i], n - 1, p, rev, ans);
			swp(0, n - 1, p, rev, ans);
			swp(i, 0, p, rev, ans);
			swp(0, n - 1, p, rev, ans);
		}*/
	}
	cout << ans.size() << endl;
	for (auto u : ans) cout << u.first + 1 << " " << u.second + 1 << endl;
	//system("pause");
	return 0;
}