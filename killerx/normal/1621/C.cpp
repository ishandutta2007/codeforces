#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#undef DEBUG

void Main() {
	int n;
	scanf("%d", &n);
	#ifdef DEBUG
	std::vector <int> p = {1, 3, 4, 2};
	std::vector <int> q(n);
	std::iota(q.begin(), q.end(), 1);
	auto ask = [&] (int x) {
		int ans = q[x];
		std::vector <int> nq(n);
		rep(i, n) nq[i] = q[p[i] - 1];
		nq.swap(q);
		return ans - 1;
	};
	#else
	auto ask = [&] (int x) {
		printf("? %d\n", x + 1);
		fflush(stdout);
		int ans;
		scanf("%d", &ans);
		return ans - 1;
	};
	#endif
	std::vector <int> perm(n, -1);
	rep(u, n) if (!~perm[u]) {
		std::vector <int> vec;
		int x;
		while ((x = ask(u)) != u);
		vec.push_back(x);
		while ((x = ask(u)) != u) vec.push_back(x);
		rep(i, vec.size()) perm[vec[i]] = vec[(i + 1) % vec.size()];
	}
	printf("! ");
	rep(i, n) printf("%d ", perm[i] + 1);
	printf("\n");
	fflush(stdout);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}