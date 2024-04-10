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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

string s;

int fastsolve() {
		int n = s.length();
		
		//s = "MFF";
		if (s == "MFFFM") 
			s = s;
		int a = -2, t = 0, cnt = 0;
		int was = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'F') {
				if (was == 2) {
					int when = i - a - 1;
					int nt = max(0, t - when + 1);
					ans = max(ans, i - cnt + nt);
					t = nt;
				}
				a = i;
				cnt += s[i] == 'F';
				if (was == 1) {
					ans = i - cnt + 1;
					was = 2;
				}
			} else was = max(was, 1);
		}
		return ans;
		if (cnt == 0 || cnt == n) return 0;
		return t + a - cnt + 1;
}

void gen() {
	int n = rand() % 100 + 1;
	s = "";
	for (int i = 0; i < n; i++) {
		if (rand() % 2) s += 'F';
		else s += 'M';
	}
}

int slowsolve() {
	string S = s;
	int n = S.length();
	for (int ans = 0; ans < 1e9; ans++) {
		bool ok = 1;
		for (int i = n - 1; i > 0; i--) {
			if (S[i] == 'F' && S[i - 1] == 'M') {
				swap(S[i], S[i - 1]);
				i--;
				ok = 0;
			}
		}
		if (ok) return ans;
	}
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0; it < 10000; it++) {
		gen();
		int ans1 = fastsolve();
		int ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << ans1 << " " << ans2 << endl << s << endl;
			break;
		}
		cerr << it << " " << s.length() << " " << ans1 << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stress(0);

	while (cin >> s) {
		cout << fastsolve() << endl;
	}

	return 0;
}