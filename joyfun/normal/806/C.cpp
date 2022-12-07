#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int n;
multiset<ll> S;
map<ll, int> cnt;
ll a[N];

bool judge(int c, ll up) {
	multiset<ll>::iterator it = S.end();
	for (int i = 0; i < c; i++) {
		it--;
		if (it == S.begin()) return false;
		if (up > *it * 2) return false;
		up /= 2;
	}
	it = S.end(); it--;
	for (int i = 0; i < c; i++) {
		S.erase(it--);
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll x; scanf("%lld", &x);
		a[i] = x;
		cnt[x]++;
	}
	sort(a + 1, a + 1 + n);
	int c1 = 0, c2 = 0, tot = 0;
	while (cnt[1]) {
		for (ll i = 1; ; i *= 2) {
			if (cnt[i] == 0) {
				S.insert(i / 2);
				break;
			}
			cnt[i]--;
		}
		tot++;
	}
	for (int i = n; i >= 1; i--) {
		if (cnt[a[i]] == 0) continue;
		cnt[a[i]]--;
		ll j = 1;
		while (j * 2 <= a[i]) j *= 2;
		if (S.size() == 0) {
			printf("-1\n");
			return 0;
		}
		multiset<ll>::iterator it = S.end(); it--;
		if (*it < j) {
			printf("-1\n");
			return 0;
		}
		S.erase(it);
	}
	int r = tot, l = tot;
	for (multiset<ll>::iterator it = S.begin(); it != S.end(); ) {
		ll j = 1;
		int cnt = 1;
		while (j < *it) {
			j *= 2;
			cnt++;
		}
		if (judge(cnt, j)) {
			l--;
		} else break;
		S.erase(it++);
	}
	for (int i = l; i <= r; i++) printf("%d ", i); printf("\n");
	return 0;
}