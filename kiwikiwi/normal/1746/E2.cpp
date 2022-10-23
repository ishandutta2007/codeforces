#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

mt19937_64 rnd(random_device{}()); 
int v = 1, rd = 0;
bool c = false;
bool DEBUG = 0;

bool query(basic_string<int> s) {
	rd++;
	printf("? %d", (int)s.size());
	bool is = 0;
	if (!DEBUG) {
		for (auto x : s) {
			printf(" %d", x);
			if (x == v) is = 1;
		}
	}
	puts("");
	fflush(stdout);
	if (DEBUG) {
		if (c) { c = false; return is; }
		else {
			if (rand() % 2) {
				c = false;
				return is;
			} else {
				c = true;
				return !is;
			}
		}
	} else {
		char t[10];
		scanf("%s", t);
		return (t[0] == 'Y');
	}
}

bool answer(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	if (DEBUG) {
		return x == v;
	} else {
		char t[10];
		scanf("%s", t);
		return (t[1] == ')');
	}
}

int n, dp[110][110];
array<int, 2> op[110][110];

int calc(int s1, int s2) {
	if (dp[s1][s2] != -1) return dp[s1][s2];
	if (s1 + s2 <= 2) return dp[s1][s2] = 0;
	dp[s1][s2] = 1 << 30;
	for (int p1 = 0; p1 <= s1; p1++) {
		for (int p3 = 0; p3 <= s2; p3++) {
			int p2 = s1 - p1, p4 = s2 - p3;
			int val = max(calc(p2 + p3, p1), calc(p1 + p4, p2));
			if (val + 1 < dp[s1][s2]) {
				dp[s1][s2] = val + 1;
				op[s1][s2] = {p1, p3};
			}
		}
	}
	if (dp[s1][s2] >= 1e5) {
		dp[s1][s2] = -1;
		return 1 << 30;
	} else return dp[s1][s2];
}

map<pair<int, int>, array<int, 3> > px;
array<int, 3> getdp(int x, int y) {
	if (x + y <= 100) {
		calc(x, y);
		return {dp[x][y], op[x][y][0], op[x][y][1]};
	}
	int ans = 1 << 30;
	pair<int, int> op(-1, -1);
	if (px.count({x, y})) return px[{x, y}];
	vector<int> v1{x / 2 - 1, x / 2, x / 2 + 1}, v2{y / 2 - 1, y / 2, y / 2 + 1};
	for (int p1 : v1) {
		for (int p3 : v2) {
			int p2 = x - p1, p4 = y - p3;
			if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0) continue;
			auto val = max(getdp(p2 + p3, p1), getdp(p1 + p4, p2));
			if (val[0] + 1 < ans) {
				ans = val[0] + 1;
				op = {p1, p3};
			}
		}
	}

	//printf("%d %d %d\n",x,y,ans);
	return px[{x, y}] = {ans, op.first, op.second};
}
pair<int, int> getdiv(int x, int y) {
	auto ans = getdp(x, y);
	return {ans[1], ans[2]};
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	basic_string<int> st, sf;
	for (int i = 1; i <= n; i++) {
		st.push_back(i);
	}
	while (st.size() + sf.size() >= 3) {
		auto [m1, m2] = getdiv(st.size(), sf.size());
		basic_string<int> s1 = st.substr(0, m1);
		basic_string<int> s2 = st.substr(m1);
		basic_string<int> s3 = sf.substr(0, m2);
		basic_string<int> s4 = sf.substr(m2);
		bool ans = query(s2 + s3);
		if (ans) st = s2 + s3, sf = s1;
		else st = s1 + s4, sf = s2;
		if (DEBUG) 
			fprintf(stderr, "SZ %d %d\n", (int)st.size(), (int)sf.size());
	}
	auto ans = st + sf;
	for (auto x : ans) if (answer(x)) break;
	if (DEBUG) 
		fprintf(stderr, "ROUND %d\n", rd);
}