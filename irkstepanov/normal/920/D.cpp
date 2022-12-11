#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 5050;

struct data {
    int y;
    int taken;
    data() : y(-1), taken(-1) {}
    data(int y, int taken) : y(y), taken(taken) {}
};

data dp[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, v;
    cin >> n >> k >> v;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    dp[0][a[0] % k] = {0, 1};
    for (int i = 1; i < n; ++i) {
        dp[i][a[i] % k] = {0, 1};
        for (int s = 0; s < k; ++s) {
            if (dp[i - 1][s].y == -1) {
                continue;
            }
            dp[i][s] = {s, 0};
            int nx = (s + a[i]) % k;
            dp[i][nx] = {s, 1};
        }
    }

    if (sum < v) {
        cout << "NO\n";
        return 0;
    }
    if (v % k == 0) {
        cout << "YES\n";
        for (int i = 1; i < n; ++i) {
            if (a[i] > 0) {
                cout << (a[i] + k - 1) / k << " " << i + 1 << " 1\n";
                a[0] += a[i];
                a[i] = 0;
            }
        }
        if (v > 0) cout << v / k << " " << "1 2\n";
        return 0;
    }
    if (dp[n - 1][v % k].y == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<bool> nice(n, false);
    int rem = v % k;
    for (int i = n - 1; i >= 0; --i) {
        data d = dp[i][rem];
        if (d.taken == 1) {
            nice[i] = true;
        }
        rem = d.y;
    }

    int t = -1;
    for (int i = 0; i < n; ++i) {
        if (nice[i]) {
            t = i;
        }
    }
    assert(t != -1);
    cout << "YES\n";

    for (int i = 0; i < n; ++i) {
        if (nice[i] && t != i && a[i] > 0) {
            cout << (a[i] + k - 1) / k << " " << i + 1 << " " << t + 1 << "\n";
            a[t] += a[i];
            a[i] = 0;
        }
    }
    assert(a[t] % k == v % k);
    int s = 0;
    if (s == t) {
        s = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (i == t || i == s || a[i] == 0) {
            continue;
        }
        cout << (a[i] + k - 1) / k << " " << i + 1 << " " << s + 1 << "\n";
        a[s] += a[i];
        a[i] = 0;
    }

    if (a[t] < v) {
        int rem = (v - a[t]) / k;
        cout << rem << " " << s + 1 << " " << t + 1 << "\n";
    } else if (a[t] > v) {
        int rem = (a[t] - v) / k;
        cout << rem << " " << t + 1 << " " << s + 1 << "\n";
    }

}