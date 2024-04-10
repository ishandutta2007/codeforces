#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct Ans {
	int dx, dy;
};

int h, v;
std::vector <int> l, p;
std::vector <int> l0, l1, p0, p1;
std::vector <Ans> ans;
std::bitset <2000010> can[1005];

bool div(std::vector <int> v, std::vector <int> &v0, std::vector <int> &v1) {
	can[0].reset();
	can[0].set(1000005);
	rep(i, v.size()) can[i + 1] = can[i] << v[i] | can[i] >> v[i];
	if (!can[v.size()].test(1000005)) return 0;
	v0.clear();
	v1.clear();
	int x = 1000005;
	for (int i = int(v.size()) - 1; ~i; -- i) {
		if (x - v[i] >= 0 && can[i].test(x - v[i])) v1.push_back(v[i]), x -= v[i];
		else v0.push_back(v[i]), x += v[i];
	}
	if (v0.size() > v1.size()) swap(v0, v1);
	return 1;
}

std::vector <Ans> solve(std::vector <int> vx, std::vector <int> vy) {
	sort(vx.rbegin(), vx.rend());
	sort(vy.begin(), vy.end());
	std::vector <Ans> ans;
	rep(i, vx.size()) ans.push_back({vx[i], 0}), ans.push_back({0, vy[i]});
	return ans;
}

void Main() {
	scanf("%d", &h);
	l.resize(h);
	rep(i, h) scanf("%d", &l[i]);
	scanf("%d", &v);
	p.resize(v);
	rep(i, v) scanf("%d", &p[i]);
	if (h != v) {
		puts("No");
		return ;
	}
	if (!div(l, l0, l1)) {
		puts("No");
		return ;
	}
	if (!div(p, p0, p1)) {
		puts("No");
		return ;
	}
	bool flag = 0;
	if (l0.size() > p0.size()) {
		swap(l0, p0);
		swap(l1, p1);
		flag = 1;
	}
	ans.clear();
	auto a = solve(l0, std::vector <int> (p0.begin(), p0.begin() + l0.size()));
	rep(i, a.size()) ans.push_back(a[i]);
	auto b = solve(std::vector <int> (l1.begin(), l1.begin() + p0.size() - l0.size()), std::vector <int> (p0.begin() + l0.size(), p0.end()));
	rep(i, b.size()) ans.push_back({-b[i].dx, b[i].dy});
	auto c = solve(std::vector <int> (l1.begin() + p0.size() - l0.size(), l1.end()), p1);
	rep(i, c.size()) ans.push_back({-c[i].dx, -c[i].dy});
	if (flag) {
		rep(i, ans.size()) {
			std::swap(ans[i].dx, ans[i].dy);
		}
	}
	puts("Yes");
	int x = 0, y = 0;
	rep(i, ans.size()) {
		x += ans[i].dx;
		y += ans[i].dy;
		printf("%d %d\n", x, y);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}