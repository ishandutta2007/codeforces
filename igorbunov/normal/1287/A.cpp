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

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	int now = -100000;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			now = 0;
			continue;
		}
		now++;
		ans = max(now, ans);
	}
	cout << ans << endl;

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	solve();
    }

}