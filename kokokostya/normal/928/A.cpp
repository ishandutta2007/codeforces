


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <random>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string t;
	cin >> t;
	for (int i = 0; i < t.length(); i++)
		if(isalpha(t[i]))
			t[i] = tolower(t[i]);
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (s.length() != t.length())
			continue;
		for (int i = 0; i < s.length(); i++)
			if (isalpha(s[i]))
				s[i] = tolower(s[i]);
		bool ws = 1;
		for (int i = 0; i < s.length(); i++) {
			bool is = 1;
			if (s[i] == t[i]) {
				is = 0;
			}
			if (s[i] == '1' && t[i] == 'l') {
				is = 0;
			}
			if (s[i] == '1' && t[i] == 'i') {
				is = 0;
			}
			if (s[i] == 'l' && t[i] == 'i') {
				is = 0;
			}
			if (s[i] == 'l' && t[i] == '1') {
				is = 0;
			}
			if (s[i] == 'i' && t[i] == '1') {
				is = 0;
			}
			if (s[i] == 'i' && t[i] == 'l') {
				is = 0;
			}
			if (s[i] == 'o' && t[i] == '0') {
				is = 0;
			}
			if (s[i] == '0' && t[i] == 'o') {
				is = 0;
			}
			if (is)
				ws = 0;
		}
		if (ws) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}