#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
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

#define data NE_data
#define rank NE_rank
#define endl '\n'
#define int long long

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

int nok(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int now = 1;
    for (int i = 0; i < n; i++) {
        if (now <= 1000000002LL) {
            now = nok(now, i + 2);
        }
        if (arr[i] % now == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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