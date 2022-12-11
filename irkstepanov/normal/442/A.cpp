#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

int cnt[5][5];

bool bit(int mask, int pos)
{
    return mask & (1 << pos);
}

int f(int x)
{
    int ans = 0;
    while (x) {
        if (x & 1) {
            ++ans;
        }
        x >>= 1;
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char c;
        int d;
        cin >> c >> d;
        if (c == 'R') {
            ++cnt[0][d - 1];
        } else if (c == 'B') {
            ++cnt[1][d - 1];
        } else if (c == 'G') {
            ++cnt[2][d - 1];
        } else if (c == 'Y') {
            ++cnt[3][d - 1];
        } else {
            ++cnt[4][d - 1];
        }
    }

    int ans = 100500;
    for (int a = 0; a < 32; ++a) {
        for (int b = 0; b < 32; ++b) {
            int m[5][5];
            bool t = false;
            bool ok = true;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (bit(a, i) && bit(b, j)) {
                        m[i][j] = 0;
                    } else {
                        m[i][j] = cnt[i][j];
                        if (!bit(a, i) && !bit(b, j) && cnt[i][j]) {
                            if (!t) {
                                t = true;
                            } else {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
            }
            if (!ok) {
                continue;
            }
            for (int step = 0; step <= 100; ++step) {
                for (int i = 0; i < 5; ++i) if (bit(a, i)) {
                    int c = 0;
                    for (int j = 0; j < 5; ++j) {
                        if (m[i][j]) {
                            ++c;
                        }
                    }
                    if (c == 1) {
                        for (int j = 0; j < 5; ++j) {
                            m[i][j] = 0;
                        }
                    }
                }
                for (int j = 0; j < 5; ++j) if (bit(b, j)) {
                    int c = 0;
                    for (int i = 0; i < 5; ++i) {
                        if (m[i][j]) {
                            ++c;
                        }
                    }
                    if (c == 1) {
                        for (int i= 0; i < 5; ++i) {
                            m[i][j] = 0;
                        }
                    }
                }
            }
            int c = 0;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (m[i][j]) {
                        ++c;
                    }
                }
            }
            if (c <= 1) {
                ans = min(ans, f(a) + f(b));
            }
        }
    }

    cout << ans << "\n";

}