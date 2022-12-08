#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	vector<int> cur;
	int ans = n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur.push_back(a[i]);
		sort(cur.begin(), cur.end());
		reverse(cur.begin(), cur.end());
		int f = 0;
		for (int i = 0; i < cur.size(); i += 2) {
			f += cur[i];
		}
		if (f > h) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}