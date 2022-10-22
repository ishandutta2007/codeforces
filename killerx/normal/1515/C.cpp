#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	std::vector <std::pair <int, int> > h(n);
	rep(i, n) scanf("%d", &h[i].first), h[i].second = i;
	std::sort(h.begin(), h.end());
	std::vector <int> ans(n);
	std::set <std::pair <int, int> > st;
	rep(i, m) st.insert({0, i});
	rep(i, n) {
		int v = h[i].first, id = h[i].second;
		int mx = st.begin()->first + x - v;
		auto it = st.upper_bound(std::make_pair(mx, n));
		if (it == st.begin()) {
			printf("NO\n");
			return ;
		}
		// -- it;
		it = st.begin();
		int h = it->first, tid = it->second;
		st.erase(it);
		ans[id] = tid;
		st.insert({h + v, tid});
	}
	printf("YES\n");
	rep(i, n) printf("%d ", ans[i] + 1);
	printf("\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}