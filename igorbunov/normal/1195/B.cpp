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
	int n, k;
	cin >> n >> k;
	int a = 2 * (n + k);

	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			int b = i;
			int c = a / i;

			if (b + 3 == c) {
				cout << n - b;
				return 0;
			}

			if (c + 3 == b) {
				cout << n - c;
				return 0;
			}
		}
	}
}