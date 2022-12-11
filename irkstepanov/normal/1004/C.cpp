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
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<bool> first(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        if (s.count(a[i])) {
            first[i] = false;
        } else {
            first[i] = true;
        }
        s.insert(a[i]);
    }

    s.clear();
    vector<int> diff(n);
    for (int i = n - 1; i >= 0; --i) {
        s.insert(a[i]);
        diff[i] = sz(s);
    }

    ll ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (!first[i]) {
            continue;
        }
        //cout << i << " " << diff[i + 1] << endl;
        ans += diff[i + 1];
    }
    cout << ans << "\n";

}