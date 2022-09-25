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

string s;

int solve() {
	int res = 0;
	for (int i = 0; i < s.length(); i++)
		res = (2 * res + (s[i] == '1')) % mod;
	for (int i = 1; i < s.length(); i++)
		res = 2 * res % mod;
	return res;
}

string f(int x, int n) {
	string res = "";
	for (int i = 0; i < n; i++) {
		res = (char)(x % 2 + '0') + res;
		x >>= 1;
	}
	return res;
}

void lol() {
	for (int n = 1; n <= 6; n++) {
		for (int x = 0; x < 1 << n; x++) {
			int res = 0;
			for (int i = 0; i < 1 << n; i++) {
				for (int j = i + 1; j < 1 << n; j++) {
					if ((i ^ x) > (j ^ x)) res++;
				}
			}
			s = f(x, n);
			cout << n << " " << f(x, n) << " " << res << " " << solve() << endl;
		}
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	//lol();

	cin >> s;
	cout << solve() << endl;

	return 0;
}