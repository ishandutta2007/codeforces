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


void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int a = 3; a < 50000; a += 2) {
		int b = ((a * a - 1) >> 1);
		if (b + 1 > n) {
			break;
		}
		ans++;
	}
	cout << ans << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
	}

}