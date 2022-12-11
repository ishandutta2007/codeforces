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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, a, b;
    cin >> k >> a >> b;

    string s;
    cin >> s;

    if (k * b < sz(s) || k * a > sz(s)) {
        cout << "No solution\n";
        return 0;
    }

    vector<int> v;
    for (int i = 0; i < k; ++i) {
        v.pb(a);
    }
    int sum = k * a;
    int ptr = 0;
    while (sum < sz(s)) {
        if (v[ptr] == b) {
            ++ptr;
            continue;
        }
        ++v[ptr];
        ++sum;
    }

    int pos = 0;
    for (int x : v) {
        for (int j = 0; j < x; ++j) {
            cout << s[pos + j];
        }
        cout << "\n";
        pos += x;
    }

}