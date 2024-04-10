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
typedef long double ld;
typedef pair<ll, ll> pll;

void place(const vector<int>& v, vector<int>& ans) {
    assert(sz(v) >= 2);
    for (int i = 0; i < sz(v); ++i) {
        ans[v[i]] = v[(i + 1) % sz(v)];
    }
}

void solve(vector<int>& ans, int& n) {
    int k = 0;
    while ((1 << k) <= n) {
        ++k;
    }
    --k;
    int j = (1 << k);
    int i = j - 1;
    while (j <= n) {
        ans[i] = j;
        ans[j] = i;
        --i, ++j;
    }
    n = i;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    if (n % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> s(n + 1);
        int old = n;
        while (n >= 2) {
            solve(s, n);
        }
        n = old;
        for (int i = 1; i <= n; ++i) {
            cout << s[i] << " ";
        }
        cout << "\n";
    }

    int d = n;
    while (d % 2 == 0) {
        d /= 2;
    }
    if (d == 1 || n == 3 || n == 5) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<int> q6 = {0, 3, 6, 1, 5, 4, 2};
    vector<int> q7 = {0, 3, 6, 7, 5, 4, 2, 1};

    if (n == 6) {
        for (int i = 1; i <= n; ++i) {
            cout << q6[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    for (int i = 1; i <= 7; ++i) {
        cout << q7[i] << " ";
    }
    int k = 3;
    while ((1 << k) <= n) {
        assert((1 << k) < n);
        int lf = (1 << k);
        int rg = min(n, (1 << (k + 1)) - 1);
        for (int i = lf; i <= rg; ++i) {
            if (i != rg) {
                cout << i + 1 << " ";
            } else {
                cout << lf << " ";
            }
        }
        ++k;
    }

    cout << "\n";

}