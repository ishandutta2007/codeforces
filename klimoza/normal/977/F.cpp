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


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	map<int, int> ff;
	int maxin = 0;
	for (int i = 0; i < n; i++) {
		ff[a[i]] = ff[a[i] - 1] + 1;
		if (ff[a[i]] > ff[maxin]) maxin = a[i];
	}
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == maxin) {
			ans.push_back(i + 1);
			maxin--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}