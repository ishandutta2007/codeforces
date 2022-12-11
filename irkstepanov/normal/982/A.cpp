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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    bool ok = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '1' && s[i + 1] == '1') {
            ok = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] != '0') {
            continue;
        }
        bool empt = true;
        if (i - 1 >= 0 && s[i - 1] == '1') {
            empt = false;
        }
        if (i + 1 < n && s[i + 1] == '1') {
            empt = false;
        }
        if (empt) {
            ok = false;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

}