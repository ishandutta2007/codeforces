#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int nmax = 1e4 + 100;

bool dp[nmax];
int first[nmax];

void add(int x) {
    for (int j = nmax - 1; j >= 0; --j) {
        if (dp[j]) {
            dp[j + x] = true;
        }
    }
    int lst = -1;
    for (int j = nmax - 1; j >= 0; --j) {
        if (dp[j]) {
            lst = j;
        }
        first[j] = lst;
    }
}

int get(int x) {
    if (x < 0) {
        x = 0;
    }
    return first[x];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a, b;
    vector<int> aa(n), bb(n);
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> bb[i];
    }

    for (int i = 0; i < n; ++i) {
        int x = aa[i], y = bb[i];
        if (y) {
            a.pb(x);
        } else {
            b.pb(x);
        }
    }

    if (a.empty()) {
        cout << "0\n";
        return 0;
    }

    sort(all(a));
    sort(all(b));

    for (int i = 0; i < nmax; ++i) {
        dp[i] = false;
        first[i] = -1;
    }
    dp[0] = true;
    first[0] = 0;
    for (int x : b) {
        add(x);
    }

    vector<int> pref(sz(a));
    pref[0] = a[0];
    for (int i = 1; i < sz(a); ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    int ans = 0;

    for (int pos = sz(a) - 1; pos >= 0; --pos) {
        int sum = 0;
        for (int i = pos - 1; i >= -1; --i) {
            int t = get(l - sum);
            if (t != -1) {
                t += sum;
                if (i == -1) {
                    if (t >= l && t <= r) {
                        ans = max(ans, 1);
                    }
                } else {
                    if (t >= l && t <= r && t + pref[i] <= r) {
                        ans = max(ans, i + 2);
                    }
                }
            }

            if (i >= 0) {
                sum += a[i];
            }
        }
        add(a[pos]);
    }

    cout << ans << endl;

}