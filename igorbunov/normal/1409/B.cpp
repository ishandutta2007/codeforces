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
	int a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	int ans = 1000000000000000000LL;
	for (int i = 0; i < 2; ++i) {
		int now1 = min(n, a - x);
		a -= now1;
		n -= (now1);
		int now2 = min(n, b - y);
		b -= now2;
		ans = min(ans, a * b);
		n += now1;
		a += now1;
		b += now2;
		swap(a, b);
		swap(x, y);
	}
	cout << ans << endl;
	return;
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