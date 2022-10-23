#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

mt19937_64 rnd(random_device{}()); 
int v = 2, rd = 0;
bool c = false;
bool DEBUG = 0;

bool query(basic_string<int> s) {
	rd++;
	printf("? %d", (int)s.size());
	bool is = 0;
	for (auto x : s) {
		printf(" %d", x);
		if (x == v) is = 1;
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

int n;
pair<int, int> getdiv(int x, int y) {
	if (x == 2 && y == 1) return {2, 1};
	else return {x / 2, y / 2};
}
int main() {
	//srand(1);
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