#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

mt19937_64 rnd(random_device{}()); 

const int M = 30;
const int N = 323456;

template<class T>
struct BIT {
	T c[N];
	int size;
	void init(int s) {
		size = s;
		for (int i = 1; i <= s; i++) c[i] = 0;
	}
	T query(int x) {
		T s = 0;
		for (; x; x -= x & (-x)) {
			s += c[x];
		}
		return s;
	}
	void modify(int x, T s) {
		for (; x <= size; x += x & (-x)) {
			c[x] += s;
		}
	} 
};

BIT<int> cnt[M + 10];
int n, q, a[N];
ull seed[M + 10];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < M; i++) {
		seed[i] = rnd();
		cnt[i].init(n);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < M; j++) {
			if (((a[i] * seed[j]) >> 40) & 1) {
				cnt[j].modify(i, 1);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			for (int j = 0; j < M; j++) {
				int v = 0;
				if (((a[x] * seed[j]) >> 40) & 1) --v;
				if (((y * seed[j]) >> 40) & 1) ++v;
				if (v) cnt[j].modify(x, v);
			}
			a[x] = y;
		} else {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			bool pk = true;
			for (int j = 0; j < M; j++) {
				if ((cnt[j].query(r) - cnt[j].query(l - 1)) % k != 0) {
					pk = false;
					break;
				}
			}
			if (pk) puts("YES");
			else puts("NO");
		}
	}
}