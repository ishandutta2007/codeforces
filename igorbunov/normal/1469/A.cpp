#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	if (s[0] == ')' || s.back() == '(' || ((n % 2) != 0)) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}