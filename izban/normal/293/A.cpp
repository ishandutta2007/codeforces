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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
string s, t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> s >> t) {
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < 2 * n; i++) {
			a += s[i] == '1' && t[i] == '1';
			b += s[i] == '1' && t[i] == '0';
			c += s[i] == '0' && t[i] == '1';
		}

		int cnt[2]; cnt[0] = 0; cnt[1] = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (a) {
				cnt[i % 2]++;
				a--;
				continue;
			}
			if (i & 1) {
				if (c) {
					cnt[1]++;
					c--;
				} else if (b) {
					b--;
				}
			} else {
				if (b) {
					cnt[0]++;
					b--;
				} else if (c) {
					c--;
				}
			}
		}

		if (cnt[0] > cnt[1]) cout << "First";
		if (cnt[0] == cnt[1]) cout << "Draw";
		if (cnt[0] < cnt[1]) cout << "Second";
		cout << endl;
	}

	return 0;
}