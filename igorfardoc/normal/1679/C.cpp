#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

void update(vi& t, int now, int l, int r, int pos, int val) {
	if(l == r) {
		t[now] = val;
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(t, now * 2, l, mid, pos, val);
	} else {
		update(t, now * 2 + 1, mid + 1, r, pos, val);
	}
	t[now] = t[now * 2] + t[now * 2 + 1];
}

int get(vi& t, int now, int l, int r, int l1, int r1) {
	if(l1 > r || l > r1) return 0;
	if(l1 <= l && r <= r1) return t[now];
	int mid = (l + r) / 2;
	return get(t, now * 2, l, mid, l1, r1) + get(t, now * 2 + 1, mid + 1, r, l1, r1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, q;
	cin >> n >> q;
	vi t1(4 * n + 7, 0), t2(4 * n + 7, 0);
	map<int, int> amx;
	map<int, int> amy;
	for(int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			++amx[x];
			++amy[y];
			if(amx[x] == 1) update(t1, 1, 0, n - 1, x, 1);
			if(amy[y] == 1) update(t2, 1, 0, n - 1, y, 1);
		} else if(t == 2) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			--amx[x];
			--amy[y];
			if(amx[x] == 0) update(t1, 1, 0, n - 1, x, 0);
			if(amy[y] == 0) update(t2, 1, 0, n - 1, y, 0);
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			--x1; --y1; --x2; --y2;
			auto fir = get(t1, 1, 0, n - 1, x1, x2);
			auto sec = get(t2, 1, 0, n - 1, y1, y2);
			if(fir == x2 - x1 + 1 || sec == y2 - y1 + 1) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}