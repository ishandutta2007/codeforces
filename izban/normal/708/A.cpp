#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	
	string s;
	while (cin >> s) {
		int n = s.length();
		int i = 0;
		while (i < n && s[i] == 'a') i++;
		int j = i;
		while (j < n && s[j] != 'a') j++;

		if (i == n) {
			s[n - 1] = 'z';
			cout << s << endl;
			continue;
		}
		while (i < j) s[i++]--;
		cout << s << endl;
	}

	return 0;
}