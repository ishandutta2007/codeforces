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
	int x;
	cin >> x;
	int ind = 1LL;
	int now = 0LL;
	int ans = 0LL;
	while (true) {
		if (x - 2LL * now >= ind * ind) {
			x -= 2LL * now;
			x -= ind * ind;
			now += now + ind * ind;
			ind *= 2LL;
			ans++;
		} else {
			break;
		}
	}
	cout << ans << endl;
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