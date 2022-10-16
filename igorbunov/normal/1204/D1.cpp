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

	int now = 0;
	string ans;

	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			ans.push_back('0');
			now++;
		} else {
			if (now == 0) {
				ans.push_back('0');
			} else {
				ans.push_back('1');
				now--;
			}
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans;

}