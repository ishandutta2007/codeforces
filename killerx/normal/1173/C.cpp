#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
#define pb push_back
#define mp make_pair
using ll = long long;
using vi = vector <int>;
using pii = pair <int, int>;
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (auto it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int main() {
	int n = read();
	set <int> a;
	rep(i, n) {
		int x = read();
		if (x) a.insert(x);
	}
	deque <int> b;
	rep(i, n) {
		b.push_back(read());
	}
	int nw = 1;
	bool ok = 0;
	rep(i, n) if (b[i] == 1) {
		bool can = 1;
		for (int j = i; j + 1 < n; ++ j) {
			if (b[j] + 1 != b[j + 1]) {
				can = 0;
			}
		}
		if (can) {
			ok = 1;
			nw = b[n - 1] + 1;
		}
	}
	bool succ = 1;
	set <int> tmp = a;
	deque <int> tmpp = b;
	for (int i = nw; i <= n; ++ i) {
		if (tmp.count(i)) {
			tmpp.push_back(i);
			if (tmpp.front()) tmp.insert(tmpp.front());
			tmpp.pop_front();
		} else {
			succ = 0; break;
		}
	}
	if (succ) {
		printf("%d\n", n - nw + 1);
		return 0;
	}
	auto chk = [&] (int empt) {
		tmp = a;
		tmpp = b;
		for (int i = 0; i < empt; ++ i) {
			tmpp.push_back(0);
			if (tmpp.front()) tmp.insert(tmpp.front());
			tmpp.pop_front();
		}
		bool succ = 1;
		for (int i = 1; i <= n; ++ i) {
			if (tmp.count(i)) {
				tmpp.push_back(i);
				if (tmpp.front()) tmp.insert(tmpp.front());
				tmpp.pop_front();
			} else {
				succ = 0; break;
			}
		}
		return succ;
	};
	int lb = 1, rb = n;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (chk(md)) rb = md;
		else lb = md + 1;
	}
	printf("%d\n", lb + n);
	return 0;
}