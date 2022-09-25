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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
	set<char> a;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		a.insert(s[i]);
	cout << (a.size() & 1 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;

	return 0;
}