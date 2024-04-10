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
	int n;
	cin >> n;
	cout << n + 5 << endl;
	if (n <= 128) {
		for (int i = 3; i < n; i++) {
			cout << i << " " << n << endl;
		}
		for (int i = 0; i < 8; i++) {
			cout << n << " " << 2 << endl;
		}
	} else {
		for (int i = 3; i < 64; i++ ) {
			cout << i << " " << n << endl;
		}
		for (int i = 65; i < n; i++) {
			cout << i << " " << n << endl;
		}
		for (int i = 0; i < 3; i++) {
			cout << n << " " << 64 << endl;
		}
		for (int i = 0; i < 6; i++) {
			cout << 64 << " " << 2 << endl;
		}
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