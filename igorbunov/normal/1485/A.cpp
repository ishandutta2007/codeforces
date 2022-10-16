#include <algorithm>
#include <iostream>
#include <cstdlib>
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
 
using namespace std;

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"



int cnt(int a, int b) {
	if (b == 1) {
		return 1000000000LL;
	}
	int ans = 0;
	while (a != 0) {
		ans++;
		a /= b;
	}
	return ans;
}
void solve() {
	int a, b;
	cin >> a >> b;
	int ans = 1000000000LL;
	for (int i = 0; i < 100; i++) {
		ans = min(ans, i + cnt(a, b + i));
	}
	cout << ans << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}