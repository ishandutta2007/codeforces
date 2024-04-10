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
	string s;
	cin >> s;
	if (s == "0") {
		cout << 0;
		return 0;
	}
	int ans = (s.size() + 1) / 2;
	string t = "1";

	for (int i = 0; i < 101; i++) {
		if (s == t) {
			ans--;
		}
		t += "00";
	}

	cout << ans;

}