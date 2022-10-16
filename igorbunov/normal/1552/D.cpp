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
//#define int long long

vector<int> vals;
int need;
bool was = false;
void gen(int ind = 0, int now = 0) {
    if (was) {
        return;
    }
    if (ind == vals.size()) {
        was |= need == now;
        return;
    }
    gen(ind + 1, now);
    gen(ind + 1, now + vals[ind]);
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cout << "YES\n";
            return;
        }
    }
    if (n == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        vals.clear();
        need = arr[i];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            vals.push_back(arr[j]);
            vals.push_back(-arr[j]);
        }
        was = false;
        gen();
        if (was) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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