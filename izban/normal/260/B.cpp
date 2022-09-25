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
const int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string s;
map<string, int> mp;

int strtoint(string s) {
	stringstream ss;
	int ans;
	ss << s;
	ss >> ans;
	return ans;
}

bool correct(string s) {
	if (s[2] != '-' || s[5] != '-') return 0;
	for (int i = 0; i < s.length(); i++)
		if (i != 2 && i != 5 && s[i] == '-') 
			return 0;
	int y = strtoint(s.substr(6, 4));
	if (!(y >= 2013 && y <= 2015)) return 0;
	int m = strtoint(s.substr(3, 2));
	if (!(m >= 1 && m <= 12)) return 0;
	int d = strtoint(s.substr(0, 2));
	if (!(d >= 1 && d <= a[m])) return 0;
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> s;
	for (int i = 0; i + 10 <= s.length(); i++) {
		string cur = s.substr(i, 10);
		if (correct(cur))
			mp[cur]++;
	}

	string ans = "";
	for (map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++)
		if (it->second > mp[ans])
			ans = it->first;
	cout << ans;

	return 0;
}