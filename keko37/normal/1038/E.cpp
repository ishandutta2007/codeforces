#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, sol;
int val[5];
vector <int> v[6];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		int a, b, c;
		cin >> a >> c >> b;
		if (a > b) swap(a, b);
		if (a == b) val[a] += c;
		if (a == 1 && b == 2) v[0].push_back(c); if (a == 2 && b == 3) v[1].push_back(c);
		if (a == 3 && b == 4) v[2].push_back(c); if (a == 1 && b == 4) v[3].push_back(c);
		if (a == 1 && b == 3) v[4].push_back(c); if (a == 2 && b == 4) v[5].push_back(c);
	}
	for (int i=0; i<6; i++) v[i].push_back(0);
	for (int i=0; i<6; i++) sort(v[i].begin(), v[i].end());
	int ma = v[0].size()-1, mb = v[1].size()-1, mc = v[2].size()-1;
	int md = v[3].size()-1, me = v[4].size()-1, mf = v[5].size()-1;
	int dp[2] [mb+1] [mc+1] [md+1] [me+1] [mf+1] [5];
	int res;
	for (int a = 0; a<=ma; a++) {
		for (int b = 0; b<=mb; b++) {
			for (int c = 0; c<=mc; c++) {
				for (int d = 0; d<=md; d++) {
					for (int e = 0; e<=me; e++) {
						for (int f = 0; f<=mf; f++) {
							res = 0;
							if (a == 0 && e == 0 && d == 0) {
								dp[1] [b] [c] [d] [e] [f] [1] = val[1] + (a<ma||b<mb||f<mf)*val[2] + (b<mb||c<mc||e<me)*val[3] + (c<mc||d<md||f<mf)*val[4];
							} else {
								if (a) res = max(res, v[0] [a] + dp[0] [b] [c] [d] [e] [f] [2]);
								if (e) res = max(res, v[4] [e] + dp[1] [b] [c] [d] [e-1] [f] [3]);
								if (d) res = max(res, v[3] [d] + dp[1] [b] [c] [d-1] [e] [f] [4]);
								dp[1] [b] [c] [d] [e] [f] [1] = res;
							}
							res = 0;
							if (a == 0 && b == 0 && f == 0) {
								dp[1] [b] [c] [d] [e] [f] [2] = val[2] + (a<ma||e<me||d<md)*val[1] + (b<mb||c<mc||e<me)*val[3] + (c<mc||d<md||f<mf)*val[4];
							} else {
								if (a) res = max(res, v[0] [a] + dp[0] [b] [c] [d] [e] [f] [1]);
								if (f) res = max(res, v[5] [f] + dp[1] [b] [c] [d] [e] [f-1] [4]);
								if (b) res = max(res, v[1] [b] + dp[1] [b-1] [c] [d] [e] [f] [3]);
								dp[1] [b] [c] [d] [e] [f] [2] = res;
							}
							res = 0;
							if (b == 0 && e == 0 && c == 0) {
								dp[1] [b] [c] [d] [e] [f] [3] = val[3] + (a<ma||e<me||d<md)*val[1] + (a<ma||b<mb||f<mf)*val[2] + (c<mc||d<md||f<mf)*val[4];
							} else {
								if (b) res = max(res, v[1] [b] + dp[1] [b-1] [c] [d] [e] [f] [2]);
								if (e) res = max(res, v[4] [e] + dp[1] [b] [c] [d] [e-1] [f] [1]);
								if (c) res = max(res, v[2] [c] + dp[1] [b] [c-1] [d] [e] [f] [4]);
								dp[1] [b] [c] [d] [e] [f] [3] = res;
							}
							res = 0;
							if (c == 0 && f == 0 && d == 0) {
								dp[1] [b] [c] [d] [e] [f] [4] = val[4] + (a<ma||e<me||d<md)*val[1] + (a<ma||b<mb||f<mf)*val[2] + (b<mb||c<mc||e<me)*val[3];
							} else {
								if (c) res = max(res, v[2] [c] + dp[1] [b] [c-1] [d] [e] [f] [3]);
								if (f) res = max(res, v[5] [f] + dp[1] [b] [c] [d] [e] [f-1] [2]);
								if (d) res = max(res, v[3] [d] + dp[1] [b] [c] [d-1] [e] [f] [1]);
								dp[1] [b] [c] [d] [e] [f] [4] = res;
							}
						}
					}
				}
			}
		}
		for (int b = 0; b<=mb; b++) {
			for (int c = 0; c<=mc; c++) {
				for (int d = 0; d<=md; d++) {
					for (int e = 0; e<=me; e++) {
						for (int f = 0; f<=mf; f++) {
							dp[0] [b] [c] [d] [e] [f] [1] = dp[1] [b] [c] [d] [e] [f] [1];
							dp[0] [b] [c] [d] [e] [f] [2] = dp[1] [b] [c] [d] [e] [f] [2];
							dp[0] [b] [c] [d] [e] [f] [3] = dp[1] [b] [c] [d] [e] [f] [3];
							dp[0] [b] [c] [d] [e] [f] [4] = dp[1] [b] [c] [d] [e] [f] [4];
						}
					}
				}
			}
		}
	}
	sol = max(sol, dp[0] [mb] [mc] [md] [me] [mf] [1]);
	sol = max(sol, dp[0] [mb] [mc] [md] [me] [mf] [2]);
	sol = max(sol, dp[0] [mb] [mc] [md] [me] [mf] [3]);
	sol = max(sol, dp[0] [mb] [mc] [md] [me] [mf] [4]);
	cout << sol;
	return 0;
}