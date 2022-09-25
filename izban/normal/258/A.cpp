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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> s;
	if (s.length() == 1) {
		cout << 0;
		return 0;
	}
	bool f = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0' && !f || i == (int) s.length() - 1 && !f)
			f = 1;
		else
			cout << s[i];
	}

	return 0;
}