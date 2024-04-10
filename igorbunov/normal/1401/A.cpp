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

int calc (int a, int b) {
	if (a > b) {
		return a * b;
	}
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1 * a * b;
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (n < k) {
		cout << k - n << endl;
		return;
	}
	if (n % 2 != k % 2) {
		cout << 1 << endl;
		return;
	} else {
		cout << 0 << endl;
		return;
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