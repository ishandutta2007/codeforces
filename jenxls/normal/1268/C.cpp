#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define int ll

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 2e5 + 20;
int n, a[N], plc[N];

int res[N];

int fen[N];

inline void add (int p, int val) {
    for (p++; p < N; p += p & -p) fen[p] += val;
}

inline int get (int p) {
    int sum = 0;
    for (; p; p -= p & -p) sum += fen[p];
    return sum;
}

inline int get (int l, int r) {
    return get(r) - get(l);
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        plc[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        res[n] += get(plc[i] + 1, n);
        add(plc[i], 1);
    }

    for (int i = n - 1; i >= 1; i--) {
        res[i] = res[i + 1];

        int left = get(0, plc[i]), right = get(plc[i] + 1, n);

        assert(left + right == i);

        add(plc[i], -1);

        if (left < right) {
            res[i] -= right;
            res[i] += left;

            int low = -1, high = n;

            while (high - low > 1) {
                int mid = (low + high) / 2;

                if (get(0, mid) <= (i - 1) / 2) low = mid;
                else high = mid;
            }

            res[i] -= (low - plc[i]) - get(plc[i] + 1, low + 1);
        }
        else {
            int low = -1, high = n;

            while (high - low > 1) {
                int mid = (low + high) / 2;

                if (get(mid + 1, n) <= (i - 1) / 2) high = mid;
                else low = mid;
            }

            if (plc[i] > high)
                res[i] -= (plc[i] - high) - get(high, plc[i]);
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
}