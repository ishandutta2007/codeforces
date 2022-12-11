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

const int sigma = 26;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> cnt(sigma, 0);
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        int j = s[i] - 'a';
        ++cnt[j];
    }

    if (n == 1) {
        cout << "Yes\n";
        return 0;
    }

    bool ok = false;
    for (int i = 0; i < sigma; ++i) {
        if (cnt[i] >= 2) {
            ok = true;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

}