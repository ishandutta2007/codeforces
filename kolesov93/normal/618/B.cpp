#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 111;
int a[N][N];
int ans[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    memset(ans, -1, sizeof(ans));
    for (int cur = 1; cur <= n; ++cur) {
        for (int pos = 1; pos <= n; ++pos)
            if (ans[pos] == -1) {
                bool cool = true;
                for (int i = 1; i <= n; ++i) {
                    if (i == pos) continue;
                    if (ans[i] == -1) {
                        if (a[pos][i] != cur) {
                            cool = false;
                            break;
                        } else {
                            continue;
                        }
                    }

                    if (a[pos][i] != ans[i]) {
                        cool = false;
                        break;
                    }
                }

                if (cool) {
                    ans[pos] = cur;
                    break;
                }
            }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}