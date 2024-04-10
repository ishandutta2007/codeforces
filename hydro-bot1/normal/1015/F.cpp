// Hydro submission #62c565f38672efa577bec6de@1657103859627
#include <bits/stdc++.h>
using namespace std;

#ifdef KAMIRULEZ
	const bool kami_loc = true;
	const long long kami_seed = 69420;
#else
	const bool kami_loc = false;
	const long long kami_seed = chrono::steady_clock::now().time_since_epoch().count();
#endif

const string kami_fi = "kamirulez.inp";
const string kami_fo = "kamirulez.out";
mt19937_64 kami_gen(kami_seed);

long long rand_range(long long rmin, long long rmax) {
	uniform_int_distribution<long long> rdist(rmin, rmax);
	return rdist(kami_gen);
}

void file_io(string fi, string fo) {
	if (fi != "" && (!kami_loc || fi == kami_fi)) {
		freopen(fi.c_str(), "r", stdin);
	}
	if (fo != "" && (!kami_loc || fo == kami_fo)) {
		freopen(fo.c_str(), "w", stdout);
	}
}

void set_up() {
	if (kami_loc) {
		file_io(kami_fi, kami_fo);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void just_do_it();

void just_exec_it() {
	if (kami_loc) {
		auto pstart = chrono::steady_clock::now();
		just_do_it();
		auto pend = chrono::steady_clock::now();
		long long ptime = chrono::duration_cast<chrono::milliseconds>(pend - pstart).count();
		string bar(50, '=');
		cout << '\n' << bar << '\n';
		cout << "Time: " << ptime << " ms" << '\n';
	}
	else {
		just_do_it();
	}
}

int main() {
	set_up();
	just_exec_it();
	return 0;
}
const int ms = 2e2 + 20;
const int mod = 1e9 + 7;
int nxt[ms][2];
int sf[ms];
int dp[ms][ms][ms][2];

void just_do_it() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[0] == '(') {
		nxt[0][0] = 1;
		nxt[0][1] = 0;
	}
	else {
		nxt[0][1] = 1;
		nxt[0][0] = 0;
	}
	sf[0] = 0;
	for (int i = 1; i <= (int)s.size() - 1; i++) {
		if (s[i] == '(') {
			nxt[i][0] = i + 1;
			nxt[i][1] = nxt[sf[i]][1];
			sf[i + 1] = nxt[sf[i]][0];
		}
		else {
			nxt[i][1] = i + 1;
			nxt[i][0] = nxt[sf[i]][0];
			sf[i + 1] = nxt[sf[i]][1];
		}
	}
	nxt[(int)s.size()][0] = nxt[sf[(int)s.size()]][0];
	nxt[(int)s.size()][1] = nxt[sf[(int)s.size()]][1];
	dp[0][0][0][0] = 1;
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j <= (int)s.size(); j++) {
			for (int k = 0; k <= n; k++) {
				for (int l = 0; l < 2; l++) {
					for (int m = 0; m < 2; m++) {
						int ni = i + 1;
						int nj = nxt[j][m];
						int nk = k + (m == 0 ? 1 : -1);
						int nl = l | (nj == (int)s.size());
						if (nk >= 0) {
							dp[ni][nj][nk][nl] += dp[i][j][k][l];
							if (dp[ni][nj][nk][nl] >= mod) {
								dp[ni][nj][nk][nl] -= mod;
							}
						}
					}
				}
			}
		}
	}
	int res = 0;
	for (int j = 0; j <= (int)s.size(); j++) {
		res += dp[n * 2][j][0][1];
		if (res >= mod) {
			res -= mod;
		}
	}
	cout << res;
}