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
int n, m;
int sum[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> s >> m) {
		n = s.length();
		sum[0] = n > 1 && s[0] == s[1];
		for (int i = 1; i < s.length() - 1; i++) sum[i] = sum[i - 1] + (s[i] == s[i + 1]);
		for (int i = 0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			l--; r--;
			cout << sum[r - 1] - (l ? sum[l - 1] : 0) << endl;
		}
	}

	return 0;
}