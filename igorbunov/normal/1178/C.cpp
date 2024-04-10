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
	int w, h;
	cin >> w >> h;
	int c = w + h;

	int ans = 1;

	for (int i = 0; i < c; i++) {
		ans *= 2;
		ans %= 998244353;
	}

	cout << ans;
}