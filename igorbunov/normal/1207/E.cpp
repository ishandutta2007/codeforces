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

signed main() {
	cout << "? ";

	for (int i = 1; i <= 100; i++) {
		cout << i << " ";
	}

	int ans = 0;

	int x;
	cin >> x;

	for (int i = 7; i < 14; i++) {
		if ((x & (1 << i)) > 0) {
			ans += (1 << i);
		}
	}

	int now = 128;

	cout << endl;

	cout << "? ";

	for (int i = 0; i < 100; i++) {
		cout << now << " ";
		now += 128;
	}

	cout << endl;

	cin >> x;
	for (int i = 0; i < 7; i++) {
		if ((x & (1 << i)) > 0) {
			ans += (1 << i);
		}
	}

	cout << "! " << ans;
}