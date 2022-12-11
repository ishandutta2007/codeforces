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
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    if (s[0] != 'a') {
        cout << "NO\n";
        return 0;
    }
    int la = 0;
    int ra = 0;
    while (ra + 1 < sz(s) && s[ra + 1] == 'a') {
        ++ra;
    }

    if (ra == sz(s) - 1) {
        cout << "NO\n";
        return 0;
    }
    if (s[ra + 1] != 'b') {
        cout << "NO\n";
        return 0;
    }

    int lb = ra + 1;
    int rb = lb;
    while (rb + 1 < sz(s) && s[rb + 1] == 'b') {
        ++rb;
    }

    if (rb == sz(s) - 1) {
        cout << "NO\n";
        return 0;
    }

    bool ok = true;
    for (int i = rb + 1; i < sz(s); ++i) {
        if (s[i] != 'c') {
            ok = false;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    int cnta = ra - la + 1;
    int cntb = rb - lb + 1;
    int cntc = sz(s) - 1 - (rb + 1) + 1;
    if (cntc == cnta || cntc == cntb) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}