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
	int p, f;
	cin >> p >> f;
	int cnts, cntw;
	cin >> cnts >> cntw;
	int s, w;
	cin >> s >> w;
	if (s > w) {
		swap(s, w);
		swap(cnts, cntw);
	}
	int ans = 0;
	for (int i = 0; i <= cnts; i++) {
		if (i * s > p) {
			break;
		}
		int now = i;
		int p1 = p - i * s;
		int cs;
		int cw;
		if (p1 / w >= cntw) {
			cw = 0;
			now += cntw;
		} else {
			cw = cntw - (p1 / w);
			now += (p1 / w);
		}
		//cout << now << " ";
		cs = cnts - i;
		int f1;
		if (f / s >= cs) {
			//cs = 0;
			now += cs;
			f1 = f  - cs * s;
		} else {
			cs = cs - (f / s) * s;
			now += (f / s);
			f1 = f - (f / s) * s;
		}

        //cout << now <<  " ";

		if (f1 / w >= cw) {
			now += cw;
		} else {
			now += f1 / w;
		}
		//cout << i << " " << now << endl;
		ans = max(ans, now);
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