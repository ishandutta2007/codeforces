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
	int n, l, r;
	cin >> n >> l >> r;
	int ans1 = 0;

	for (int i = 0; i < n - l; i++) {
		ans1++;
	}

	int now1 = 1;
	for (int i = 0; i < l; i++) {
		ans1 += now1;
		now1 *= 2;
	}

	int ans2 = 0;

	int now2 = 1;
	for (int i = 0; i < r; i++) {
		ans2 += now2;
		now2 *= 2;
	}


	for (int i = 0; i < n - r; i++) {
		ans2 += now2 / 2;
	}

	cout << ans1 << " " << ans2 << endl;


}