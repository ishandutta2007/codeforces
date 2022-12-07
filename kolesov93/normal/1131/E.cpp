#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 100111;
ll f[N][26];
int cur[26];
char w[N];

void up(ll& x, ll y) {
    if (y > x) x = y;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int I = 0; I < n; ++I) {
        scanf("%s", w);
        int m = strlen(w);

        memset(cur, 0, sizeof(cur));
        int current = w[0] - 'a';
        int strike = 1;
        cur[current] = 1;
        for (int i = 1; i < m; ++i) {
            if (current == w[i] - 'a') {
                ++strike;
            } else {
                current = w[i] - 'a';
                strike = 1;
            }
            cur[current] = max(cur[current], strike);
        }

        for (int letter = 0; letter < 26; ++letter) {
            if (I == 0) {
                f[I][letter] = cur[letter];
                continue;
            }

            f[I][letter] = cur[letter];
            if (cur[letter] == 0 && f[I - 1][letter]) f[I][letter] = 1;

            if ((w[0] - 'a' == letter || w[m - 1] - 'a' == letter) && f[I - 1][letter] && cur[letter] != m) {
                int lcnt = 0, rcnt = 0;
                for (int i = 0; w[i] - 'a' == letter; ++i) lcnt += 1;
                for (int i = m - 1; w[i] - 'a' == letter; --i) rcnt += 1;
                up(f[I][letter], lcnt + rcnt + 1);
            }

            if (cur[letter] == m) {
                double val = double(f[I - 1][letter]) * (1 + cur[letter]) + cur[letter];
                ll vall = f[I - 1][letter] * (1 + cur[letter]) + cur[letter];
                if (val < 2e9) {
                    up(f[I][letter], vall);
                }
            }
        }
    }

    int best = 0;
    for (int i = 1; i < 26; ++i) {
        if (f[n - 1][i] > f[n - 1][best]) best = i;
    }
    cout << f[n - 1][best] << endl;

    return 0;
}