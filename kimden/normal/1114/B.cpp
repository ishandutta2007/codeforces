#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct o {
	int val;
	int idx;
	int flag = 0;
};

bool comp2(o& a, o& b) {
	if (a.idx == b.idx) {
		return a.val > b.val;
	}
	return a.idx < b.idx;
}
bool comp1(o& a, o& b) {
	if (a.val == b.val) {
		return a.idx < b.idx;
	}
	return a.val > b.val;
}


int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<o> a(n);
	ll sumsum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].val;
		a[i].idx = i;
	}
	sort(all(a), comp1);
	for (int i = 0; i < k * m; ++i) {
		// cerr << a[i].val << endl;
		a[i].flag = 1;
		sumsum += a[i].val;
	}
	sort(all(a), comp2);
	int sum = 0;
	cout << sumsum << endl;
	for (int i = 0; i < n; ++i) {
		sum += a[i].flag;
		if (a[i].flag && sum % m == 0 && sum != m * k) {
			cout << i + 1 << " ";
		}
	}
	cout << "\n";	

}