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
	vector<int> t1;
	vector<int> t2;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t % 2) t1.push_back(t);
		else t2.push_back(t);
	}
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	if (t1.size() == t2.size()) {
		cout << 0 << endl;
	}
	else if (t1.size() > t2.size()) {
		ll ans = 0;
		for (int i = 0; i < t1.size() - t2.size() - 1; i++) ans += t1[i];
		cout << ans << endl;
	}
	else {
		ll ans = 0;
		for (int i = 0; i < t2.size() - t1.size() - 1; i++) ans += t2[i];
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}