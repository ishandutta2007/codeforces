#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, m;

struct Function {
	int v;
	std::map <int, int> a;

	Function &operator *= (int c) {
		c %= 3;
		assert(c);
		v = v * c % 3;
		for (auto &it : a) it.second = it.second * c % 3;
		return *this;
	}

	Function &operator += (const Function &f) {
		v = (v + f.v) % 3;
		for (auto it : f.a) a[it.first] = (a[it.first] + it.second) % 3;
		for (auto it = a.begin(); it != a.end(); )
			if (it->second == 0) it = a.erase(it);
			else ++ it;
		return *this;
	}

	inline Function operator * (int c) const {
		return Function(*this) *= c;
	}

	inline Function operator + (const Function &f) const {
		return Function(*this) += f;
	}
};

bool correct;
std::vector <Function> base;

inline void add(Function f) {
	for (Function &it : base) {
		if (f.a.find(it.a.rbegin()->first) != f.a.end()) {
			f += it * (3 - f.a[it.a.rbegin()->first]);
		}
	}
	if (f.a.empty()) {
		if (f.v) correct = false;
		return ;
	}
	f *= f.a.rbegin()->second;
	base.push_back(f);
}

int adj[100][100];

void Main() {
	correct = true;
	base.clear();
	scanf("%d %d", &n, &m);
	rep(i, n) rep(j, n) adj[i][j] = -1;
	rep(i, m) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		adj[u][v] = adj[v][u] = i;
		if (~w) {
			Function f;
			f.v = w - 1;
			f.a[i] = 1;
			add(f);
		}
	}
	rep(i, n) rep(j, i) if (~adj[i][j]) {
		rep(k, j) if (~adj[i][k] && ~adj[j][k]) {
			Function f;
			f.v = 0;
			f.a[adj[i][j]] = 1;
			f.a[adj[j][k]] = 1;
			f.a[adj[i][k]] = 1;
			add(f);
		}
	}
	if (!correct) {
		puts("-1");
		return ;
	}
	/* for (auto f : base) {
		eprintf("%d = ", f.v);
		bool first = true;
		for (auto pr : f.a) {
			if (!first) eprintf(" + "); else first = false;
			eprintf("%d * x[%d]", pr.second, pr.first);
		}
		eprintf("\n");
	} */
	static int ans[256];
	rep(i, m) ans[i] = 0;
	std::sort(base.begin(), base.end(), [&] (Function i, Function j) {
		return i.a.rbegin()->first < j.a.rbegin()->first;
	});
	for (auto f : base) {
		int i = f.a.rbegin()->first;
		ans[i] = f.v;
		for (auto it : f.a) if (it.first < i) {
			ans[i] = (ans[i] + (3 - it.second) * ans[it.first]) % 3;
		}
	}
	rep(i, m) printf("%d ", ans[i] + 1);
	printf("\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}