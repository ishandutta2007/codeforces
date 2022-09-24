#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>
//#include <cassert>
void assert(bool f) {
	if (!f) {
		std::cerr << "Fail" << std::endl;
		exit(1);
	}
}
#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;


const int MAXN = 100010;
const int MAXK = 112;
const int MAXM = 910;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const int INF = (int)(1e9) + 7;

void print(vector<int> a) {
	for (int x : a) printf("%d\n", x);
}
void upd(int &x, int y) {
	x = min(x, y);
}

int f(vector<int> &a, vector<int> &b) {
	int i = 0;
	int res = INF;
	for (int j = 0; j < (int)b.size(); j++) {
		while (i < (int)a.size() && a[i] < b[j]) i++;
		if (i > 0) res = min(res, b[j] - a[i - 1]);
		if (i < (int)a.size()) res = min(res, a[i] - b[j]);
	}
	return res;
}

int t[MAXN][MAXM];
int s[MAXM][MAXK][MAXK];
vector<vector<int> > pref[MAXK], suf[MAXK];

vector<int> fastsolve(vector<int> a, vector<pair<int, int> > q) {
	int n = a.size();
	int qq = q.size();
	//for (int i = 0; i < qq; i++) q[i] = make_pair(_q[i], i);

	int K = min(n, max(1, (int)sqrt(n / 8.0)));
	int m = (n + K - 1) / K;
	cerr << K << " " << MAXK << endl;
	cerr << m << " " << MAXM << endl;
	assert(K <= MAXK && m <= MAXM);

	vector<vector<int> > b(m), bb(m);
	for (int i = 0; i < n; i++) {
		b[i / K].push_back(a[i]);
		bb[i / K].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		sort(b[i].begin(), b[i].end());
		sort(bb[i].begin(), bb[i].end(), [&](int i, int j) {
			return a[i] < a[j];
		});
	}

	vector<vector<int> > g(m, vector<int>(m, INF));
	//vector<vector<int> > t(n, vector<int>(m, INF));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) t[i][j] = INF;
	//vector<vector<vector<int> > > s(m, vector<vector<int> >(K, vector<int>(K, INF)));
	for (int i = 0; i < m; i++) for (int j = 0; j < K; j++) for (int k = 0; k < K; k++) s[i][j][k] = INF;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < (int)b[i].size(); j++) {
			g[i][i] = min(g[i][i], b[i][j] - b[i][j - 1]);
		}
		for (int j = 0; j < m; j++) if (i != j) {
			int k = 0;
			for (int l = 0; l < (int)b[i].size(); l++) {
				while (k < (int)b[j].size() && b[j][k] < b[i][l]) k++;
				int cdif = INF;
				if (k < (int)b[j].size()) cdif = min(cdif, b[j][k] - b[i][l]);
				if (k > 0) cdif = min(cdif, b[i][l] - b[j][k - 1]);
				g[i][j] = min(g[i][j], cdif);
				t[bb[i][l]][j] = cdif;
			}
		}
	}
	for (int len = 0; len < n; len++) {
		for (int i = 0; i + len < m; i++) {
			int j = i + len;
			if (i > 0) g[i - 1][j] = min(g[i - 1][j], g[i][j]);
			if (j + 1 < m) g[i][j + 1] = min(g[i][j + 1], g[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int j = i / K;
		for (int jj = j - 1; jj > 0; jj--) {
			t[i][jj - 1] = min(t[i][jj - 1], t[i][jj]);
		}
		for (int jj = j + 1; jj + 1 < m; jj++) {
			t[i][jj + 1] = min(t[i][jj + 1], t[i][jj]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i < n - 1 && (i + 1) / K == i / K) {
			for (int jj = i / K + 1; jj < m; jj++) {
				upd(t[i][jj], t[i + 1][jj]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0 && (i - 1) / K == i / K) {
			for (int jj = i / K - 1; jj >= 0; jj--) {
				upd(t[i][jj], t[i - 1][jj]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int L = i * K;
		int R = min((i + 1) * K, n);
		for (int j = L; j < R; j++) {
			for (int k = j + 1; k < R; k++) {
				s[i][j - L][k - L] = abs(a[j] - a[k]);
			}
		}
		for (int len = 0; len < K; len++) {
			for (int cl = 0; cl + len < K; cl++) {
				int cr = cl + len;
				if (cl > 0) s[i][cl - 1][cr] = min(s[i][cl - 1][cr], s[i][cl][cr]);
				if (cr + 1 < K) s[i][cl][cr + 1] = min(s[i][cl][cr + 1], s[i][cl][cr]);
			}
		}
	}
	//vector<vector<vector<int> > > pref(m, vector<vector<int> >());
	//vector<vector<vector<int> > > suf(m, vector<vector<int> >());
	/*for (int i = 0; i < m; i++) {
	continue;
	pref[i].clear();
	suf[i].clear();
	pref[i].push_back(vector<int>(1, a[i * K]));
	for (int j = 1; i * K + j < n && j < K; j++) {
	pref[i].push_back(pref[i].back());
	pref[i].back().push_back(a[i * K + j]);
	int id = pref[i].back().size() - 1;
	while (id > 0 && pref[i].back()[id] < pref[i].back()[id - 1]) {
	swap(pref[i].back()[id], pref[i].back()[id - 1]);
	id--;
	}
	}
	int o = min(n, (i + 1) * K) - 1;
	suf[i].push_back(vector<int>(1, a[o]));
	for (int j = o - 1; j >= 0 && j / K == o / K; j--) {
	suf[i].push_back(suf[i].back());
	suf[i].back().push_back(a[j]);
	int id = suf[i].back().size() - 1;
	while (id > 0 && suf[i].back()[id] < suf[i].back()[id - 1]) {
	swap(suf[i].back()[id], suf[i].back()[id - 1]);
	id--;
	}
	}
	}*/
	vector<int> aa, bbb;

	vector<int> res(qq, -1);
	for (int i = 0; i < qq; i++) {
		int L = q[i].first;
		int R = q[i].second;
		int ans = INF;

		int bL = L / K;
		if (L % K != 0) bL++;
		int bR = R / K;
		if (R % K != K - 1 && R != n - 1) bR--;
		if (bL <= bR) {
			upd(ans, g[bL][bR]);
		}

		int cL = L / K;
		int cR = R / K;
		if (cL == cR) {
			upd(ans, s[cL][L - cL * K][R - cL * K]);
		}
		else {
			upd(ans, s[cL][L - cL * K][K - 1]);
			upd(ans, s[cR][0][R - cR * K]);
			if (cL + 1 < cR) {
				upd(ans, t[L][bR]);
				upd(ans, t[R][bL]);
			}
			//int mx = min(n, (cL + 1) * K) - 1;
			//upd(ans, f(pref[cR][R - cR * K], suf[cL][mx - L]));
			aa.clear();
			bbb.clear();
			for (int i = L; i < n && i / K == L / K; i++) aa.push_back(a[i]);
			for (int i = R; i >= 0 && i / K == R / K; i--) bbb.push_back(a[i]);
			sort(aa.begin(), aa.end());
			sort(bbb.begin(), bbb.end());
			upd(ans, f(aa, bbb));
		}
		res[i] = ans;
	}
	return res;
}

int Rand(int x) {
	return abs((rand() << 15) + rand()) % x;
}

void test() {
	int n = 1e5;
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = Rand(1e9 + 1);
	int m = 3e5;
	vector<pair<int, int> > q(m);
	for (int i = 0; i < m; i++) {
		while (q[i].first == q[i].second) {
			q[i].first = Rand(n);
			q[i].second = Rand(n);
			if (q[i].first > q[i].second) swap(q[i].first, q[i].second);
		}
	}
	double st = clock() / (double)CLOCKS_PER_SEC;
	fastsolve(a, q);
	double fn = clock() / (double)CLOCKS_PER_SEC;
	cerr << fn - st << endl;
	exit(0);
}

vector<int> slowsolve(vector<int> a, vector<pair<int, int> > q) {
	int n = a.size();
	vector<int> ans;
	for (int i = 0; i < (int)q.size(); i++) {
		int res = INF;
		for (int l = q[i].first; l < q[i].second; l++) {
			for (int r = l + 1; r <= q[i].second; r++) {
				res = min(res, abs(a[l] - a[r]));
			}
		}
		ans.push_back(res);
	}
	return ans;
}

void stress() {
	for (int it = 916;; it++) {
		cerr << it << endl;
		srand(it);
		int n = rand() % 100 + 2;
		vector<int> a(n);
		for (int i = 0; i < n; i++) a[i] = Rand(500) + 1;
		int m = 1000;
		vector<pair<int, int> > q(m);
		for (int i = 0; i < m; i++) {
			while (q[i].first == q[i].second) {
				q[i].first = Rand(n);
				q[i].second = Rand(n);
				if (q[i].first > q[i].second) swap(q[i].first, q[i].second);
			}
		}
		vector<int> ans1 = fastsolve(a, q);
		vector<int> ans2 = slowsolve(a, q);
		if (ans1 != ans2) {
			cout << "----------" << endl;
			print(ans1);
			cout << "instead of" << endl;
			print(ans2);
			cout << "----------" << endl;
			cout << n << endl;
			print(a);
			cout << m << endl;
			for (int i = 0; i < m; i++) {
				cout << q[i].first << " " << q[i].second << endl;
			}
			slowsolve(a, q);
			fastsolve(a, q);
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//test();
	//stress();

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	vector<pair<int, int> > q(m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &q[i].first, &q[i].second);
		q[i].first--;
		q[i].second--;
	}
	print(fastsolve(a, q));

	return 0;
}