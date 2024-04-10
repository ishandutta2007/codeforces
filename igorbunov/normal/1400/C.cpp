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

int n;

void solve() {
	string w;
	cin >> w;
	int x;
	cin >> x;
	n = w.size();
	string s(n, '1');
	for (int i = 0; i < w.size(); i++) {
		if (w[i] == '0') {
			if (i + x < n) {
				s[i + x] = '0';
			}
			if (i >= x) {
				s[i - x] = '0';
			}
		}
	}
	//cout << s << endl;

	for (int i = 0; i < n; i++) {
	    if (w[i] == '0') {
            continue;
	    }
	    bool was = false;
	    was |= (i + x < n && s[i + x] == '1');
	    was |= (i >= x && s[i - x] == '1');
		if (!was) {
			cout << -1 << endl;
			return;
		}
	}
	cout << s << endl;
}

signed main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}