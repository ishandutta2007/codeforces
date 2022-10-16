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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int q;
	cin >> q;
	for (int _ = 0; _ < q; _++) {
		int n, k;
		cin >> n >> k;
		if (k % 3 != 0) {
			if (n % 3 == 0) {
				cout << "Bob\n";
			} else {
				cout << "Alice\n";
			}
		} else {
			n %= (k + 1);
			if (n == k) {
				cout << "Alice\n";
				continue;
			}
			if (n % 3 == 0) {
				cout << "Bob\n";
			} else {
				cout << "Alice\n";
			}
		}
	}
}