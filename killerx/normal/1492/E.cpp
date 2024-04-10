#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int count(std::vector <int> a, std::vector <int> b) {
	int cnt = 0;
	rep(i, a.size()) cnt += (a[i] != b[i]);
	return cnt;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector <std::vector <int> > a(n, std::vector <int> (m));
	rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
	std::pair <int, int> pr;
	rep(i, n) pr = std::max(pr, {count(a[0], a[i]), i});
	if (pr.first <= 2) {
		puts("Yes");
		rep(i, m) printf("%d ", a[0][i]);
		printf("\n");
		return 0;
	}
	if (pr.first > 4) {
		puts("No");
		return 0;
	}
	if (pr.first == 4) {
		std::vector <int> pos;
		rep(i, m) if (a[0][i] != a[pr.second][i])
			pos.push_back(i);
		rep(i, 4) rep(j, i) {
			int x = a[0][pos[i]];
			int y = a[0][pos[j]];
			a[0][pos[i]] = a[pr.second][pos[i]];
			a[0][pos[j]] = a[pr.second][pos[j]];
			bool flag = 1;
			rep(s, n) if (count(a[0], a[s]) > 2) flag = 0;
			if (flag) {
				puts("Yes");
				rep(s, m) printf("%d ", a[0][s]);
				printf("\n");
				return 0;
			}
			a[0][pos[i]] = x;
			a[0][pos[j]] = y;
		}
		puts("No");
		return 0;
	}
	std::vector <int> pos;
	rep(i, m) if (a[0][i] != a[pr.second][i])
		pos.push_back(i);
	rep(i, 3) rep(j, 3) if (i != j) {
		int x = a[0][pos[i]];
		a[0][pos[i]] = a[pr.second][pos[i]];
		bool flag = 1;
		std::set <int> st;
		rep(s, n) {
			int cnt = count(a[0], a[s]) - (a[0][pos[j]] != a[s][pos[j]]);
			if (cnt > 2) flag = 0;
			else if (cnt == 2) st.insert(a[s][pos[j]]);
		}
		if (st.size() >= 2) flag = 0;
		if (flag) {
			a[0][pos[j]] = st.empty() ? 233 : *st.begin();
			puts("Yes");
			rep(i, m) printf("%d ", a[0][i]);
			printf("\n");
			return 0;
		}
		a[0][pos[i]] = x;
	}
	puts("No");
	return 0;
}