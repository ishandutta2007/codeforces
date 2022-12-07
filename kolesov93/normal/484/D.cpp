#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 1000111;
int n;
int a[N];
ll f[N];

typedef vector< pair<int, ll> > cell;
cell stmin, stmax;

void push(cell& A, pair<int, ll> nval) {
    if (A.size() == 0) {
        A.push_back(nval);
        return;
    }
    A.push_back(make_pair(nval.first, max(nval.second, A.back().second)));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + (i + 1));
    }

    ll ans = 0;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int val = a[i];

        f[i] = f[i - 1];
        // max
        while (!stmin.empty() && val < stmin.back().first) stmin.pop_back();
        if (!stmin.empty()) {
            f[i] = max(f[i], ll(val) + stmin.back().second);
        }

        // min
        while (!stmax.empty() && val > stmax.back().first) stmax.pop_back();
        if (!stmax.empty()) {
            f[i] = max(f[i], -ll(val) + stmax.back().second);
        }

        push(stmin, make_pair(val, f[i - 1] - val));
        push(stmax, make_pair(val, f[i - 1] + val));

        ans = max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}