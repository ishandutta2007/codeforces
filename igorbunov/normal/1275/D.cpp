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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int first = -1;
	int last = -1;

	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (first == -1) {
				first = i;
			}
			last = i;
		}
	}

	if (first == -1) {
		cout << "YES\n";
		return;
	}

	bool can = true;
	int need = a[first] - b[first];

	if (need > 0) {
		cout << "NO\n";
		return;
	}

	for (int i = first; i <= last; i++) {
		if (a[i] - b[i] != need) {
			can = false;
			break;
		}
	}

	if (can) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}