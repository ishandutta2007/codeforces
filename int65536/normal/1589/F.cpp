#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> l;
vector<vector<int>> a;
vector<vector<vector<int>>> g;
vector<vector<int>> w;
int cache[256][1024];

int dp(int p[]) {
	int state = 0;
	if (p[0] >= 0) {
		for (int i = 0; i < n; ++i) {
			state = (state << 1) | w[i][p[i]];
		}
	}
	int& ret = (p[0] >= 0 ? cache[a[0][p[0]]][state] : cache[0][0]);
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 'A'; i <= 'z'; ++i) {
		int q[16];
		int ok = 1;
		for (int j = 0; j < n; ++j) {
			q[j] = g[j][p[j] + 1][i];
			if (q[j] < 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ret = max(ret, 1 + dp(q));
		}
	}
	return ret;
}

string construct(int p[]) {
	int ret = dp(p);
	if (ret == 0) {
		return "";
	}
	for (int i = 'A'; i <= 'z'; ++i) {
		int q[16];
		int ok = 1;
		for (int j = 0; j < n; ++j) {
			q[j] = g[j][p[j] + 1][i];
			if (q[j] < 0) {
				ok = 0;
				break;
			}
		}
		if (ok && 1 + dp(q) == ret) {
			string ret;
			ret += (char)(i);
			ret += construct(q);
			return ret;
		}
	}
	return "";
}

string solve() {
	cin >> n;
	l = vector<int>(n);
	a = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c : s) {
			a[i].push_back(c);
		}
		l[i] = s.size();
	}
	g = vector<vector<vector<int>>>(n);
	for (int i = 0; i < n; ++i) {
		auto& f = g[i];
		f = vector<vector<int>>(l[i] + 1, vector<int>(256, -1));
		for (int j = l[i] - 1; j >= 0; --j) {
			f[j] = f[j + 1];
			f[j][a[i][j]] = j;
		}
	}
	w = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		w[i] = vector<int>(l[i]);
		for (int j = 0; j < l[i]; ++j) {
			w[i][j] = (g[i][j + 1][a[i][j]] >= 0) ? 1 : 0;
		}
	}
	int p[16];
	memset(p, 255, sizeof(p));
	memset(cache, 255, sizeof(cache));
	int r1 = dp(p);
	string r2 = construct(p);
	return to_string(r1) + "\n" + r2;
}

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		cout << solve() << endl;
	}
	return 0;
}