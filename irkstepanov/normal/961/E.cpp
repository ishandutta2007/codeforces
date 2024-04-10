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

vector<int> t;
int n;

void update(int pos) {
    pos += n;
    t[pos] += 1;
    for (pos >>= 1; pos; pos >>= 1) {
        t[pos] += 1;
    }
}

int get(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans += t[l];
        }
        if (!(r & 1)) {
            ans += t[r];
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<pii> a(n);
    vector<int> val(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
        val[i + 1] = a[i].first;
    }

    sort(all(a), [&] (pii x, pii y) {
        if (x.first != y.first) {
            return x.first > y.first;
        }
        return x.second > y.second;
    });

    ++n;

    t = vector<int>(2 * n);
    ll ans = 0;
    int ptr = 0;

    for (int i = n - 1; i >= 1; --i) {
        while (ptr < sz(a) && a[ptr].first >= i) {
            update(a[ptr].second);
            ++ptr;
        }
        ans += get(i + 1, min(n - 1, val[i]));
    }

    cout << ans << "\n";

}