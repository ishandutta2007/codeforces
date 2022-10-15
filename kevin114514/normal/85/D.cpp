#include "bits/stdc++.h"
 
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using i32 = int;
using u32 = unsigned;
using i16 = short;
using u16 = unsigned short;
using ld = long double;
using ii = pair<int, int>;

const int N = 1 << 18;

int cnt[N];
i64 st[N][5];

void upd(int k, int x, int y, int lo, int hi, int no = 1) {
	if(lo == hi) st[no][0] += x * y, cnt[no] += y;
	else {
		int mid = (lo + hi) / 2;
		if(k <= mid) upd(k, x, y, lo, mid, 2 * no);
		else upd(k, x, y, mid + 1, hi, 2 * no + 1);
		cnt[no] = cnt[2 * no] + cnt[2 * no + 1];
		memset(st[no], 0, sizeof st[no]);
		for(int i = 0; i < 5; ++i) {
			st[no][i] += st[2 * no][i];
			st[no][(i + cnt[2 * no]) % 5] += st[2 * no + 1][i];
		}
	}
}

void solve() {

	int n;

	cin >> n;

	vector<string> type(n);
	vector<int> x(n), a;

	for(int i = 0; i < n; ++i) {
		cin >> type[i];
		if(type[i] != "sum") {
			cin >> x[i];
			a.push_back(x[i]);
		}
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < n; ++i) {
		if(type[i] == "sum") cout << st[1][2] << '\n';
		else {
			int k = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
			upd(k, x[i], type[i] == "add" ? 1 : -1, 0, n - 1);
		}
	}
}
 
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();
 	return 0;
}