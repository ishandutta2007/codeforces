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
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = sz(s);

    string t = s + s;
    vector<int> pref(n);
    int cnt = 1;
    for (int i = sz(t) - 2; i >= 0; --i) {
        if (t[i] != t[i + 1]) {
            ++cnt;
        } else {
            cnt = 1;
        }
        if (i < sz(s)) {
            pref[i] = cnt;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (pref[i] >= n) {
            cout << n << "\n";
            return 0;
        }
    }

    cnt = 1;
    vector<int> suff(n);
    for (int i = 1; i < sz(t); ++i) {
        if (t[i] != t[i - 1]) {
            ++cnt;
        } else {
            cnt = 1;
        }
        if (i >= sz(s)) {
            suff[i - sz(s)] = cnt;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (suff[i] >= n) {
            cout << n << "\n";
            return 0;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int j = (i - 1 + n) % n;
        ans = max(ans, pref[i]);
        ans = max(ans, suff[i]);
        if (s[i] != s[j]) {
            ans = max(ans, min(pref[i] + suff[j], n));
        }
    }

    cout << ans << "\n";

}