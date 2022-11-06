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

const int N = 3e5 + 20;

int T;

int n, a[N];
int cnt[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 0; i < 2 * n + 5; i++) {
            cnt[i] = 0;
        }

        for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

        int ans = 0;
        bool fl = 0;
        for (int i = 0; i < 2 * n + 5; i++) {
            ans += (fl + cnt[i] >= 1);

            if (fl + cnt[i] >= 2) fl = 1;
            else fl = 0;
        }

        cout << ans << '\n';
    }
}