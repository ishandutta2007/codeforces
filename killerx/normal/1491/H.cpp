#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
const int b = 333;

int n, q, cnt, fa[mxn], jump[mxn], mx[mxn / b + 5], tag[mxn / b + 5];

void rebuild(int id) {
	if (tag[id]) return ;
	int l = id * b;
	int r = std::min(n, (id + 1) * b);
	mx[id] = -0x3f3f3f3f;
	for (int i = l; i < r; ++ i) {
		mx[id] = std::max(mx[id], fa[i]);
		jump[i] = fa[i] < l ? i : jump[fa[i]];
	}
}

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) if (i) scanf("%d", &fa[i]), -- fa[i];
	cnt = (n - 1) / b + 1;
	rep(i, cnt) rebuild(i);
	while (q --) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			-- l;
			int id = l / b;
			while (l < r && l % b) {
				fa[l] = std::max(0, fa[l] - x);
				++ l;
			}
			rebuild(id);
			while (l + b <= r) {
				if (mx[l / b] >= l) {
					for (int i = l; i < n && i < l + b; ++ i)
						fa[i] = std::max(0, fa[i] - x);
					rebuild(l / b);
				} else {
					tag[l / b] = std::min(n, tag[l / b] + x);
				}
				l += b;
			}
			id = l / b;
			while (l < r) {
				fa[l] = std::max(0, fa[l] - x);
				++ l;
			}
			rebuild(id);
		} else {
			int u, v;
			scanf("%d %d", &u, &v);
			-- u, -- v;
			while (jump[u] != jump[v]) {
				if (u / b > v / b) std::swap(u, v);
				v = std::max(0, fa[jump[v]] - tag[jump[v] / b]);
			}
			if (u > v) std::swap(u, v);
			while (u != v) {
				if (u > v) std::swap(u, v);
				v = std::max(0, fa[v] - tag[v / b]);
			}
			printf("%d\n", u + 1);
		}
	}
	return 0;
}