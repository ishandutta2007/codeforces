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


//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if ((s[i] - '0') % 2 == 0) {
				a0++;
			} else {
				a1++;
			}
		} else {
			if ((s[i] - '0') % 2 == 0) {
				b0++;
			} else {
				b1++;
			}
		}
	}
	if (n % 2 == 0) {
		if (b0) {
			cout << 2;
		} else {
			cout << 1;
		}
	} else {
		if (a1) {
			cout << 1;
		} else {
			cout << 2;
		}
	}
	cout << endl;
	return;
	bool flag = false;
	while (a0 + a1 + b0 + b1 != 1) {
		if (flag) {
			if (a0) {
				a0--;
			} else {
				a1--;
			}
		} else {
			if (b1) {
				b1--;
			} else {
				b0--;
			}
		}
		flag = !flag;
	}
	if (a0 + b0) {
		cout << 2;
	} else {
		cout << 1;
	}
	cout << endl;
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