#include<bits/stdc++.h>
#define maxn 200000
#define inf 2000000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
ll t[maxn * 4 + 7];
ll lp[maxn * 4 + 7];

void update(int now, int l, int r, int l1, int r1, int val) {
	if(l1 > r || l > r1) return;
	if(l1 <= l && r <= r1) {
		lp[now] += val;
		t[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(now * 2, l, mid, l1, r1, val);
	update(now * 2 + 1, mid + 1, r, l1, r1, val);
	t[now] = max(t[now * 2], t[now * 2 + 1]) + lp[now];
}

int get_pos(int now, int l, int r) {
	if(l == r) return l;
	int mid = (l + r) / 2;
	if(t[now * 2] >= t[now * 2 + 1]) {
		return get_pos(now * 2, l, mid);
	} else {
		return get_pos(now * 2 + 1, mid + 1, r);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t1;
	cin >> t1;
	while(t1--) {
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < 4 * n + 7; i++) {
			lp[i] = t[i] = 0;
		}
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			update(1, 0, n - 1, i, i, a[i] + i);
		}
		vector<bool> here(n, false);
		for(int i = 0; i < k; i++) {
			int pos = get_pos(1, 0, n - 1);
			here[pos] = true;
			//update(1, 0, n - 1, 0, pos, 1);
			update(1, 0, n - 1, pos, pos, -inf);
		}
		ll ans = 0;
		int now = 0;
		for(int i = 0; i < n; i++) {
			if(here[i]) {
				++now;
				continue;
			} else {
				ans += now + a[i];
			}
		}
		cout << ans << '\n';
	}
}