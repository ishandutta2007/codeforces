#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 2e5 + 5;

int n, q;
int A[mxn], B[mxn];
int L[mxn], R[mxn];
i64 s[mxn];

inline void Main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &A[i]);
	rep(i, n) scanf("%d", &B[i]);
	rep(_, q) {
		int l, r;
		scanf("%d %d", &l, &r);
		-- l;
		L[_] = l, R[_] = r;
	}
	rep(i, n) s[i + 1] = s[i] + A[i] - B[i];
	if (s[n]) {
		puts("NO");
		return ;
	}
	static std::vector <int> G[2][mxn];
	rep(i, n + 1) G[0][i].clear();
	rep(i, n + 1) G[1][i].clear();
	rep(i, q) {
		G[0][L[i]].push_back(i);
		G[1][R[i]].push_back(i);
	}
	static int deg[mxn];
	rep(i, q) deg[i] = 0;
	rep(i, q) if (s[L[i]]) ++ deg[i];
	rep(i, q) if (s[R[i]]) ++ deg[i];
	std::set <int> st;
	rep(i, n + 1) if (s[i]) st.insert(i);
	std::vector <int> que;
	rep(i, q) if (!deg[i]) que.push_back(i);
	rep(_, que.size()) {
		int qi = que[_];
		for (auto it = st.lower_bound(L[qi]); it != st.end() && *it < R[qi]; it = st.erase(it)) {
			int i = *it;
			s[i] = 0;
			for (int nqi : G[0][i]) if (!-- deg[nqi]) que.push_back(nqi);
			for (int nqi : G[1][i]) if (!-- deg[nqi]) que.push_back(nqi);
		}
	}
	if (st.empty()) puts("YES");
	else puts("NO");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
    return 0;
}