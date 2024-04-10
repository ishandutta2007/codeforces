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
#define int long long


int arr[100][100];


int ans[100][100];

bool check(int i, int j) {
    bool kek = false;
    kek |= arr[i - 1][j];
    kek |= arr[i][j - 1];
    kek |= arr[i + 1][j];
    kek |= arr[i][j + 1];

    kek |= arr[i + 1][j + 1];
    kek |= arr[i + 1][j - 1];

    kek |= arr[i - 1][j + 1];
    kek |= arr[i - 1][j - 1];
    return kek;
}
void solve() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = 0;
            ans[i][j] = 0;
        }
    }

    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m - 1; i++) {
        int x = 30;
        int y = 30 + i;
        if (!check(x, y)) {
            ans[0][i] = 1;
            arr[x][y] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int x = 30 + i;
        int y = 30 + m - 1;
        if (!check(x, y)) {
            ans[i][m - 1] = 1;
            arr[x][y] = 1;
        }
    }

    for (int i = 0; i < m - 1; i++) {
        int x = 30 + n - 1;
        int y = 30 + m - 1 - i;
        if (!check(x, y)) {
            ans[n - 1][m - 1 - i] = 1;
            arr[x][y] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int x = 30 + n - 1 - i;
        int y = 30;
        if (!check(x, y)) {
            ans[n - 1 - i][0] = 1;
            arr[x][y] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout << endl;
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