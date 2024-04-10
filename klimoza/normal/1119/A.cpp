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

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; a[i].second = i;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int ind = 0;
	int maxi = 0;
	int mini = INFi;
	while (a[ind].first == a[0].first) {
		maxi = max(maxi, a[ind].second);
		mini = min(mini, a[ind].second);
		ind++;
	}
	int maxic = maxi;
	int minic = mini;
	for (int i = ind; i < n; i++) {
		if (a[i].first == a[i - 1].first) {
			ans = max(ans, max(abs(a[i].second - maxi), abs(a[i].second - mini)));
		}
		else {
			maxi = maxic;
			mini = minic;
			ans = max(ans, max(abs(a[i].second - maxi), abs(a[i].second - mini)));
		}
		maxic = max(maxic, a[i].second);
		minic = min(minic, a[i].second);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}