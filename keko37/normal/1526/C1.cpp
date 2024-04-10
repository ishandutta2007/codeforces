#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n, sol;
llint fen[MAXN];
vector <pi> v;
map <int, int> mp;

void ubaci (int x, int k) {
    for (; x < MAXN; x += x&-x) fen[x] += k;
}

llint upit (int x) {
    llint res = 0;
    for (; x > 0; x -= x&-x) res += fen[x];
    return res;
}

void izbaci (int ind, int val) {
    while (val > 0) {
        auto it = mp.lower_bound(ind); it--;
        if (val >= (it -> second)) {
            val -= (it -> second);
            ubaci(it -> first, -(it -> second));
            mp.erase(it);
        } else {
            int pos = it -> first;
            mp[pos] -= val;
            ubaci(pos, -val);
            val = 0;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x >= 0) {
            mp[i] = x;
            ubaci(i, x);
            sol++;
        } else {
            v.push_back({-x, i});
        }
    }
    sort(v.begin(), v.end());
    for (auto pp : v) {
        int val = pp.first, ind = pp.second;
        if (upit(ind) >= val) {
            izbaci(ind, val);
            sol++;
        }
    }
    cout << sol;
    return 0;
}