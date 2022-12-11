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

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << "YES\n";
        return 0;
    }

    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            pos = i;
        }
    }

    if (pos == -1) {
        cout << "NO\n";
        return 0;
    }

    if (n - 1 > m) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < pos; ++i) {
        if (s[i] != t[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = n - 1, j = m - 1; i > pos; --i, --j) {
        if (s[i] != t[j]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

}