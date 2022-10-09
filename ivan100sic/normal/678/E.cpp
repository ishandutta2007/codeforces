#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

bool mx(ld& x, ld y) {
	if (y > x) {
		x = y;
		return true;
	} else {
		return false;
	}
}

ld eval_perm(const vector<vector<ld>>& p, const vector<int>& a) {
	int n = p.size();
	vector<ld> dist(n, 0);
	dist[a[0]] = 1;
	for (int i=1; i<n; i++) {
		int x = a[i];
		vector<ld> tmp(n, 0);
		for (int j=0; j<n; j++) {
			tmp[j] += dist[j] * p[j][x];
			tmp[x] += dist[j] * p[x][j];
		}
		swap(dist, tmp);
	}
	return dist[0];
}

void print_testcase(const vector<vector<ld>>& p, ostream& os) {
	int n = p.size();
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			os << p[i][j] << " \n"[j == n-1];
		}
	}
}

ld brute(const vector<vector<ld>>& p) {
	int n = p.size();
	vector<int> a(n), b;
	iota(a.begin(), a.end(), 0);
	ld sol = 0;
	do
		if (mx(sol, eval_perm(p, a)))
			b = a;
	while (next_permutation(a.begin(), a.end()));
	
	// auto c = max_element(p[0].begin()+1, p[0].end()) - p[0].begin();
	// if (c != b[n-2]) {
	// 	cerr << "not good\n";
	// }

	// int d = -1; ld best = -1;
	// for (int i=1; i<n; i++) {
	// 	if (i != c) {
	// 		ld val = p[0][c] * p[c][i] + p[0][i] * p[i][c];
	// 		if (d == -1 || val > best) {
	// 			best = val;
	// 			d = i;
	// 		}
	// 	}
	// }

	// if (d != b[n-3]) {
	// 	cerr << "not good 2\n";
	// 	print_testcase(p, cerr);
	// }

	return sol;
}

vector<vector<ld>> read_input() {
	int n;
	cin >> n;
	vector<vector<ld>> p(n, vector<ld>(n, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> p[i][j];
		}
	}
	return p;
}

vector<vector<ld>> generate_input(int n) {
	vector<vector<ld>> p(n, vector<ld>(n, 0));
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			ld q = uniform_real_distribution<ld>(0, 1)(eng);
			p[i][j] = q;
			p[j][i] = 1-q;
		}
	}
	return p;
}

ld greedy_1(const vector<vector<ld>>& p) {
	int n = p.size();
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	reverse(a.begin(), a.end());
	auto cmp = [&](int x, int y) {
		return p[0][x] < p[0][y];
	};
	sort(a.begin(), a.end()-1, cmp);
	return eval_perm(p, a);
}

ld greedy_2(const vector<vector<ld>>& p) {
	int n = p.size();
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	reverse(a.begin(), a.end());
	while (1) {
		bool ok = false;
		for (int i=0; i<n-1; i++) {
			for (int j=i+1; j<n; j++) {
				auto b = a;
				swap(b[i], b[j]);
				if (eval_perm(p, b) > eval_perm(p, a)) {
					a = b;
					ok = true;
				}
			}
		}
		if (!ok)
			break;
	}
	return eval_perm(p, a);
}

ld dynamic_programming(const vector<vector<ld>>& p) {
	int n = p.size();
	if (n == 1)
		return 1;
	if (n == 2)
		return p[0][1];
	vector<vector<ld>> dp(1 << n, vector<ld>(n, 0));
	dp[(1<<n)-1][0] = 1;
	for (int mask=(1<<n)-2; mask>=0; mask--) {
		for (int i=0; i<n; i++) {
			if (!(mask & (1 << i)))
				continue;
			ld w = 0;
			for (int j=0; j<n; j++) {
				if (mask & (1 << j))
					continue;
				ld v = 0;
				v += dp[mask|(1<<j)][j] * p[j][i];
				v += dp[mask|(1<<j)][i] * p[i][j];
				mx(w, v);
			}
			dp[mask][i] = w;
		}
	}
	ld sol = 0;
	for (int i=0; i<n; i++) {
		mx(sol, dp[1 << i][i]);
	}
	return sol;
}

void run() {
	int tcno = 0;
	while (1) {
		tcno++;
		auto p = generate_input(3);
		auto sol = brute(p);
		auto out = dynamic_programming(p);
		if (abs(sol - out) > 1e-7) {
			cerr << "error on testcase " << tcno << '\n';
			cerr << sol << ' ' << out << '\n';
			return;
		} else {
			cerr << "ok\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cout << setprecision(8) << fixed;
	cerr << setprecision(8) << fixed;

	// run();

	cout << dynamic_programming(read_input()) << '\n';
}