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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int b, d;
string a, c;

int fastsolve() {
	for (int j = 0; j < c.size(); j++) {
		bool ok = 0;
		for (int i = 0; i < a.size(); i++)
			ok |= a[i] == c[j];
		if (!ok) return 0;
	}
	vector<int> nxt0(a.length()), cnt0(a.length());
	for (int i = 0; i < a.length(); i++) {
		int j = i, cur = 0;
		while (cur < c.length()) {
			if (a[j] == c[cur]) cur++;
			j = (j + 1) % a.length();
			cnt0[i] += !j;
		}
		nxt0[i] = j;
	}

	vector<int> nxt1, cnt1;
	vector<int> vis(a.length());
	int curi = 0, curs = 0, j = 0;
	while (1) {
		nxt1.push_back(curi);
		cnt1.push_back(curs);
		curs += cnt0[curi];
		if (vis[curi]) break;
		vis[curi] = ++j;
		curi = nxt0[curi];
	}

	curs = cnt1[vis[curi] - 1];
	int ans = -2;
	if (curs >= b) {
		for (int i = 0; i < cnt1.size(); i++) if (cnt1[i] > b || cnt1[i] == b && nxt1[i] != 0) { ans = i - 1; break;}
		if (ans == -2) ans = cnt1.size() - 1;
	} else {
		int B = b - 1;
		B -= curs;
		ans = vis[curi] - 1;
		int cycle = cnt1[cnt1.size() - 1] - cnt1[vis[curi] - 1];
		ans += B / cycle * (cnt1.size() - vis[curi]);
		B %= cycle; B++;
		for (int i = 0; i < inf; i++) if (vis[curi] + i == cnt1.size() || cnt1[vis[curi] + i] - cnt1[vis[curi] - 1] > B || cnt1[vis[curi] + i] - cnt1[vis[curi] - 1] == B && nxt1[vis[curi] + i] != 0) { ans += i; break;}
	}
	return ans / d;
}

void gen() {
	int n = rand() % 100 + 1;
	int m = rand() % 100 + 1;
	a = "";
	for (int i = 0; i < n; i++) a += (char)(rand() % (rand() % 26 + 1) + 'a');
	c = "";
	for (int i = 0; i < m; i++) c += (char)(rand() % (rand() % 26 + 1) + 'a');
	b = rand() % 40 + 1;
	d = rand() % 40 + 1;
}

int slowsolve() {
	string s1 = "", s2 = "";
	for (int i = 0; i < b; i++) s1 += a;
	for (int i = 0; i < d; i++) s2 += c;
	int ci = 0;
	for (int it = 0; it < inf; it++) {
		int cj = 0;
		while (ci < s1.size() && cj < s2.size()) {
			if (s1[ci] == s2[cj]) cj++;
			ci++;
		}
		if (ci == s1.size() && cj != s2.size()) return it;
	}
}

void stress() {
	for (int it = 0; it < inf; it++) {
		gen();
		if (fastsolve() != slowsolve()) {
			cout << b << " " << d << endl << a << " " << c << endl;
			cout << fastsolve() << " " << slowsolve() << endl;
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
    
	if (0) stress();

	cin >> b >> d >> a >> c;
	cout << fastsolve() << endl;

	return 0;
}