#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int inf = (int)(1e9);

bool bit(int mask, int pos)
{
    return mask & (1 << pos);
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("mine.txt", "w", stdout);

    int xs, ys;
    scanf("%d%d", &xs, &ys);

    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        x[i] -= xs;
        y[i] -= ys;
    }

    xs = ys = 0;

    vector<int> d1(n);
    vector<vector<int> > d2(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        d1[i] = x[i] * x[i] + y[i] * y[i];
        for (int j = 0; j < n; ++j) {
            d2[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        }
    }

    vector<int> dp(1 << n), p(1 << n);
    dp[0] = 0;
    p[0] = -1;

    for (int mask = 1; mask < (1 << n); ++mask) {
        dp[mask] = inf;
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                int relax = 2 * d1[i] + dp[mask - (1 << i)];
                if (relax < dp[mask]) {
                    dp[mask] = relax;
                    p[mask] = mask - (1 << i);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                for (int j = i + 1; j < n; ++j) {
                    if (bit(mask, j)) {
                        int relax = d1[i] + d2[i][j] + d1[j] + dp[mask - (1 << i) - (1 << j)];
                        if (relax < dp[mask]) {
                            dp[mask] = relax;
                            p[mask] = mask - (1 << i) - (1 << j);
                        }
                    }
                }
                break;
            }
        }
    }

    cout << dp.back() << "\n";
    cout << "0 ";
    int mask = (1 << n) - 1;
    while (mask) {
        int prev = p[mask];
        for (int i = 0; i < n; ++i) {
            if (bit(mask, i) && !bit(prev, i)) {
                cout << i + 1 << " ";
            }
        }
        mask = prev;
        cout << "0 ";
    }
    cout << "\n";

}