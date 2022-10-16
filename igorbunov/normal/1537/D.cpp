#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
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

#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "Bob\n";
        return;
    }
    int cnt = 0;
    while (n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    if (n != 1 || n == 1 && (cnt % 2 == 0)) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}
signed main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}