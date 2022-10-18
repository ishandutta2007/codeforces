#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

//#define endl "\n"
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> pref(m, -1);
    string s, t;
    cin >> s >> t;
    int last = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == t[last]) {
    		pref[last] = i;
    		last++;
    		if (last == m) {
    			break;
    		}
    	}
    }


    last = m - 1;
    vector<int> suf(m, -1);
    for (int i = n - 1; i >= 0; i--) {
    	if (s[i] == t[last]) {
    		suf[last] = i;
    		last--;
    		if (last == -1) {
    			break;
    		}
    	}
    }

    int ans = 1;

    for (int i = 0; i < m - 1; i++) {
    	ans = max(ans, suf[i + 1] - pref[i]);
    }

    cout << ans << endl;
}