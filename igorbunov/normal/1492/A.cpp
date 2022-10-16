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

void solve() {
    int p, a, b, c;
    cin >> p >> a >> b >> c;
    int ans = a - (p % a);
    ans = min(ans, b - (p % b));
    ans = min(ans, c - (p % c));
    if (p % a == 0) {
        ans = 0;
    }
    if (p % b == 0) {
        ans = 0;
    }
    if (p % c == 0) {
        ans = 0;
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