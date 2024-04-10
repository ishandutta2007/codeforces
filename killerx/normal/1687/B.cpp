#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, m;
int w[505];

inline int ask(std::string s) {
	printf("? %s\n", s.c_str());
	fflush(stdout);
	int L;
	scanf("%d", &L);
	return L;
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, m) {
		std::string s(m, '0');
		s[i] = '1';
		w[i] = ask(s);
	}
	std::vector <int> id(m);
	std::iota(id.begin(), id.end(), 0);
	std::sort(id.begin(), id.end(), [&] (int i, int j) {
		return w[i] < w[j];
	});
	std::string cur(m, '0');
	int curL = 0;
	for (int i : id) {
		std::string W = cur;
		W[i] = '1';
		int WL = ask(W);
		if (WL == curL + w[i]) cur = W, curL = WL;
	}
	printf("! %d\n", curL);
	fflush(stdout);
    return 0;
}