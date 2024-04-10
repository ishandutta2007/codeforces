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

string s;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while (getline(cin, s)) {
		string cur = "";
		bool f = 0;
		s += ' ';
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '"') {
				if (f) {
					f = 0;
					cout << "<" << cur << ">\n";
					cur = "";
				} else {
					f = 1;
				}
				continue;
			}
			if (f) {
				cur += s[i];
				continue;
			}
			if (s[i] == ' ') {
				if (cur != "") {
					cout << "<" << cur << ">\n";
					cur = "";
				}
				continue;
			}
			cur += s[i];
		}
	}

	return 0;
}