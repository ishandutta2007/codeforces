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
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long
#define double long double

const int maxn = 1 << 17;
const int inf = 1000000007;

string s;

string nulls(int x) {
	string ans = "0000";
	for (int i = 1; i < x; i++)
		ans += ":0000";
	return ans;
}

string norm(string s) {
	while (s.length() < 4)
		s = "0" + s;
	return s;
}

string nxt(string s, int & i) {
	string ans = "";
	if (s[i] == ':')
		ans = "z";
	while (i < s.length() && s[i] != ':')
		ans += s[i++];
	i++;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		cin >> s;
		/*if (s == "::") {
			cout << nulls(8) << endl;
			continue;
		}*/

		int i = s[0] == ':';
		vector<string> v;
		while (i < s.length())
			v.push_back(nxt(s, i));
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != "z")
				cout << norm(v[i]) << ":\n"[i == (int)v.size() - 1];
			else
				cout << nulls(8 - (int)v.size() + 1) << ":\n"[i == (int)v.size() - 1];
		}
	}

	return 0;
}