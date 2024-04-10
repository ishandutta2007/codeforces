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
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	vector<bool> arr(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '<') {
			cnt1++;
		}
		if (s[i] == '>') {
			cnt2++;
		}
		if (s[i] == '-') {
			arr[i] = true;
			arr[(i + 1) % n] = true;
			cnt3++;
		}
	}
	if (cnt1 * cnt2 == 0) {
		cout << n << endl;
	} else {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += arr[i];
		}
		cout << ans << endl;
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