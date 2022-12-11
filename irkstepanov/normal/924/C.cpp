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

    vector<ll> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    vector<ll> suff(n);
    suff[n - 1] = m[n - 1] - (n - 1);
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = max(suff[i + 1], m[i] - i);
    }

    ll ans = 0;
    ll k = 1;

    for (int i = 1; i < n; ++i) {
        if (m[i] == k) {
            ++k;
            continue;
        }
        if (i == n - 1) {
            ans += k - m[i] - 1;
            continue;
        }
        if (suff[i + 1] <= k - i - 1) {
            ans += k - m[i] - 1;
            continue;
        } else {
            ++k;
            ans += k - m[i] - 1;
        }
    }

    cout << ans << "\n";

}