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

	int n, m;
	cin >> n >> m;
	int ans = n * (n + 1LL) / 2LL;
	n -= m;
	m++;
	int len = n / m;
	int large = n % m;
	int small = m - large;
	ans -= large * (len + 1LL) * (len + 2LL) / 2LL;
	ans -= small * (len + 1LL) * (len) / 2LL;
	cout << ans << "\n";
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