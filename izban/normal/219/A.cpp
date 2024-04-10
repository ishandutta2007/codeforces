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


using namespace std;

const int maxn=100100;

int n, k, a[maxn];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> k >> s;
	for (int i = 0; i < s.length(); i++)
		a[s[i]]++;
	bool f = true;
	for (int i = 'a'; i <= 'z'; i++) {
		f &= a[i] % k == 0;
	}
	string ans = "";
	if (!f) {
		cout << -1;
	} else {
		for (int i = 'a'; i <= 'z'; i++) {
			for (int j = 0; j < a[i] / k; j++)
				ans += (char)i;
		}
		for (int i = 0; i < k; i++)
			cout << ans;
	}

	return 0;
}