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

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 5e5 + 20, LG = 60 + 2, mod = 1e9 + 7;

int T;

int n;
ll a[N];

int cnt[LG], ans;

ll save[LG];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    for (int i = 0; i < LG; i++)
        save[i] = (1ll << i) % mod;

    cin >> T;

    while (T--) {
        ans = 0;
        for (int i = 0; i < LG; i++) cnt[i] = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];

            for (int b = 0; b < LG; b++) {
                if (a[i] >> b & 1) cnt[b]++;
            }
        }

        for (int i = 0; i < n; i++) {
            int sum_or = 0, sum_and = 0;

            for (int b = 0; b < LG; b++) {
                if (a[i] >> b & 1) {
                    sum_and = (sum_and + save[b] * cnt[b]) % mod;
                    sum_or = (sum_or + save[b] * n) % mod;
                }
                else sum_or = (sum_or + save[b] * cnt[b]) % mod;
            }

            ans = (ans + 1ll * sum_or * sum_and) % mod;
        }

        cout << ans << '\n';
    }
}