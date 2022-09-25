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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n) {
		if (n > 0) {
			cout << n << endl;
		} else {
			n = -n;
			string s = "";
			while (n) {
				s = (char)(n % 10 + '0') + s;
				n /= 10;
			}
			string ans = "";
			if (s[s.length() - 2] > s[s.length() - 1]) {for (int i = 0; i < s.length(); i++) if (i != s.length() - 2) ans += s[i];}
			else for (int i = 0; i < s.length(); i++) if (i != s.length() - 1) ans += s[i];
			if (ans != "0") cout << "-";
			cout << ans;
			cout << endl;
		}
	}

	return 0;
}