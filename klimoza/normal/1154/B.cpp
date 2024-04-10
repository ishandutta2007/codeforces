#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	set<int> f;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f.insert(a[i]);
	}
	sort(a.begin(), a.end());
	if (f.size() > 3) {
		cout << -1 << endl;
	}
	else if (f.size() == 3) {
		int t1 = *f.begin();
		f.erase(f.begin());
		int t2 = *f.begin();
		int t3 = a[n - 1];
		if (t2 - t1 == t3 - t2) {
			cout << t3 - t2 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else if (f.size() == 2) {
		int t1 = a[0];
		int t2 = a[n - 1];
		if ((t2 - t1) % 2 == 0) {
			cout << (t2 - t1) / 2 << endl;
		}
		else {
			cout << t2 - t1 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}
	//system("pause");
	return 0;
}