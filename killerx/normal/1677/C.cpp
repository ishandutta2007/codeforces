#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;

int n, a[mxn], b[mxn];
std::vector <int> cyc[mxn];

inline void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]), -- a[i];
	rep(i, n) scanf("%d", &b[i]), -- b[i];
	std::vector <int> p(n);
	rep(i, n) p[a[i]] = b[i];
	std::vector <bool> vis(n);
	int cnt = 0;
	rep(i, n) if (!vis[i]) {
		cyc[cnt].clear();
		for (int u = i; !vis[u]; u = p[u])
			cyc[cnt].push_back(u), vis[u] = 1;
		std::vector <int> v0, v1;
		if (cyc[cnt].size() % 2 == 1 && cyc[cnt].size() > 1) {
			v0.push_back(cyc[cnt][cyc[cnt].size() - 2]);
			cyc[cnt].erase(cyc[cnt].begin() + cyc[cnt].size() - 2, cyc[cnt].begin() + cyc[cnt].size() - 1);
		}
		rep(z, cyc[cnt].size()) if (z & 1) v1.push_back(cyc[cnt][z]);
		else v0.push_back(cyc[cnt][z]);
		cyc[cnt].clear();
		while (!v0.empty()) cyc[cnt].push_back(v0.back()), v0.pop_back();
		rep(z, v1.size()) cyc[cnt].push_back(v1[z]);
		++ cnt;
	}
	std::sort(cyc, cyc + cnt, [&] (const std::vector <int> &i, const std::vector <int> &j) { return i.size() > j.size(); });
	std::vector <int> col(n);
	int sz = 0;
	rep(i, cnt) rep(j, cyc[i].size() / 2) col[cyc[i][j]] = sz ++;
	rep(i, cnt) if (cyc[i].size() & 1) col[cyc[i][cyc[i].size() / 2]] = sz ++;
	for (int i = cnt - 1; ~i; -- i) rep(j, cyc[i].size() / 2) col[cyc[i][j + (1 + cyc[i].size()) / 2]] = sz ++;
	assert(sz == n);
	long long ans = 0;
	rep(i, n) ans += std::abs(col[a[i]] - col[b[i]]);
	printf("%lld\n", ans);
	/*
	std::iota(col.begin(),col.end(),0);
	do{
		long long s=0;
		rep(i,n)s+=std::abs(col[a[i]]-col[b[i]]);
		if(s<=ans) continue;
		ans=s;
		eprintf("	%lld : ",s);
		rep(i,n)eprintf("%d ",col[i]);
		eprintf("\n");
	}while(std::next_permutation(col.begin(),col.end()));
	*/
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}