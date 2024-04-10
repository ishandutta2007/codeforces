#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define make_pair MP
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)5e5 + 7;
char s[ N ];
pair<int, int> st[ N ];
int n;
bool sol(int mid) {
	int lb = 0, rb = N, bb = 0, tb = N;
	int l1 = -2*N, l2 = 2*N;
	for (int i = 1; i <= n; i++) {
		int v1 = st[i].first, v2 = st[i].second;
		lb = max(lb, v1 - mid);
		bb = max(bb, v2 - mid);
		rb = min(rb, v1 + mid);
		tb = min(tb, v2 + mid);
		l1 = max(l1, v1 - v2 - mid);
		l2 = min(l2, v1 - v2 + mid);
		l1 = max(l1, lb - tb);
		l2 = min(l2, rb - bb);
	}
	if (lb <= rb && bb <= tb && l1 <= l2) {
		return true;
	} else {
		return false;
	}
}
char ot[ N*4 ];
void build(int mid) {
	int lb = 0, rb = N, bb = 0, tb = N;
	int l1 = -2*N, l2 = 2*N;
	for (int i = 1; i <= n; i++) {
		int v1 = st[i].first, v2 = st[i].second;
		lb = max(lb, v1 - mid);
		bb = max(bb, v2 - mid);
		rb = min(rb, v1 + mid);
		tb = min(tb, v2 + mid);
		l1 = max(l1, v1 - v2 - mid);
		l2 = min(l2, v1 - v2 + mid);
		l1 = max(l1, lb - tb);
		l2 = min(l2, rb - bb);
	}
	int cntp = 0;
	for (int i = lb; i <= rb; i++) {
		int x = i;
		int ll = bb, rr = tb;
		rr = min(rr, i - l1);
		ll = max(ll, i - l2);
		if (ll <= rr) {
			int y = rr;
			if (!x && !y) continue ;
			for (int j = 0; j < x; j++) ot[++cntp] = 'B';
			for (int j = 0; j < y; j++) ot[++cntp] = 'N';
			printf("%d\n", mid);
			printf("%s\n", ot + 1);
			exit(0);
		}
	}
	build(mid + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int v1 = 0, v2 = 0;
		scanf("%s", s + 1);
		int l = strlen(s + 1);
		for (int j = 1; j <= l; j++) {
			if (s[j] == 'B') v1++;
			else v2++;
		}
		st[i] = {v1, v2};
	}
	int ll = 0, rr = N, ans = rr;
	while (ll <= rr) {
		int mid = (ll + rr) >> 1;
		if (sol(mid)) {
			rr = mid - 1;
			ans = mid;
		} else {
			ll = mid + 1;
		}
	}
	sol(ans);
	build(ans);
	return 0;
}