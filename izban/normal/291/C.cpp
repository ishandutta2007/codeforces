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
#include <assert.h>
#include <memory.h>

using namespace std;

#define ll long long


#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17, maxk = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
unsigned int a[maxn];
string s[maxn];

unsigned int iptoint(string s) {
	s += '.';
	int i = 0;
	unsigned int ans = 0;
	for (int o = 0; o < 4; o++) {
		int cur = 0;
		while (s[i] != '.') {
			cur *= 10;
			cur += s[i++] - '0';
		}
		i++;
		ans <<= 8;
		ans += cur;
	}
	return ans;
}

string inttostr(unsigned int x) {
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	return s;
}

string inttoip(unsigned int x) {
	string s = inttostr(x & ((1 << 8) - 1));
	for (int i = 0; i < 3; i++) {
		x >>= 8;
		s = inttostr(x & ((1 << 8) - 1)) + "." + s;
	}
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			a[i] = iptoint(s[i]);
		}
		bool res = 0;
		unsigned int mask = 0;
		for (int i = 31; i > 0; i--) {
			mask += ((unsigned int)1) << i;
			set<unsigned int> st;
			for (int j = 0; j < n; j++)
				st.insert(a[j] & mask);
			if (st.size() == k) {
				cout << inttoip(mask) << endl;
				res = 1;
				break;
			}
		}
		if (!res) cout << -1 << endl;
	}

	return 0;
}