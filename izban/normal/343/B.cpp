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
const string ans[2] = {"No", "Yes"};



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	while (cin >> s) {
		vector<char> v;
		for (int i = 0; i < s.size(); i++) {
			if (!v.empty() && v.back() == s[i]) v.pop_back();
			else v.push_back(s[i]);
		}
		cout << ans[v.empty()] << endl;
	}

	return 0;
}