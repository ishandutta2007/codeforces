#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 5010;
const int inf = 1000000007;
const int mod = 1000000007;

string s;
int n;
int a[maxn];
int gr[maxn];

int mex(vector<int> v) {
	sort(v.begin(), v.end());
	int i = 0;
	for (int ans = 0; ans < inf; ans++) {
		if (i < v.size() && v[i] == ans) while (i < v.size() && v[i] == ans) i++;
		else return ans;
	}
}

int getgr(int x) {
	if (x == -1) return 0;
	if (gr[x] != -1) return gr[x];
	if (x == 0) return gr[x] = 0;
	vector<int> v;
	for (int i = 1; i <= x; i++) {
		v.push_back(getgr(i - 2) ^ getgr(x - i - 1));
	}
	return gr[x] = mex(v);
}

string inttostr(int x) {
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	return s;
}

string fastsolve() {
	n = s.length();
	a[0] = a[s.length() - 1] = 0;
	for (int i = 1; i + 1 < s.length(); i++) a[i] = s[i - 1] == s[i + 1];
	vector<int> v;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i] == 1;
		if (a[i] == 0 && cur) v.push_back(cur), cur = 0;
	}
	int res = 0;
	for (int i = 0; i < v.size(); i++) res ^= getgr(v[i]);
	
	if (!res) {
		return "Second\n";
	}

	bool ok = 0;
	cur = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && cur != -1) {
			for (int j = cur; j < i; j++) {
				int nres = res;
				nres ^= getgr(i - cur);
				nres ^= getgr(j - cur - 1);
				nres ^= getgr(i - j - 2);
				if (!nres) {
					return "First\n" + inttostr(j + 1) + "\n";
				}
			}
			cur = -1;
		} else if (a[i] == 1 && cur == -1) cur = i;
	}
}

int GR[maxn][maxn];

int GETGR(int L, int R) {
	if (GR[L][R] != -1) return GR[L][R];
	if (R - L < 2) return GR[L][R] = 0;
	vector<int> v;
	for (int i = L + 1; i < R; i++) if (s[i - 1] == s[i + 1]) {
		v.push_back(GETGR(L, i - 1) ^ GETGR(i + 1, R));
	}
	return GR[L][R] = mex(v);
}

string slowsolve() {
	n = s.length();
	memset(GR, -1, sizeof(GR));
	GETGR(0, n - 1);
	if (!GR[0][n - 1]) return "Second\n";
	for (int i = 1; i < n - 1; i++) {
		if (s[i - 1] == s[i + 1] && (GR[0][i - 1] ^ GR[i + 1][n - 1]) == 0) {
			return "First\n" + inttostr(i + 1) + "\n";
		}
	}
}

void gen() {
	s = "";
	int n = rand() % 10 + 1;
	for (int i = 1; i <= n; i++) s += (char)('a' + rand() % 3);
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0; it < 10000; it++) {
		gen();
		string s1 = fastsolve();
		string s2 = slowsolve();
		if (s1 != s2) {
			cout << s << endl;
			cout << s1 << "instead of\n" << s2;
			cout << it << endl;
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(gr, -1, sizeof(gr));

	stress(0);
	while (cin >> s) {
		cout << fastsolve();
	}

	return 0;
}