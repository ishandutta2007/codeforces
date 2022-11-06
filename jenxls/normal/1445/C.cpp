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

int T;

int p, q;

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> p >> q;

        if (p % q) {
            cout << p << '\n';
            continue;
        }

        vector <pii> vec;

        for (int x = 2; x * x <= q; x++) {
            if (q % x) continue;
        
            int cnt = 0;
            while (q % x == 0) q /= x, cnt++;

            vec.pb({x, cnt});
        }

        if (q > 1) vec.pb({q, 1});

        int ans = 1;
        for (pii X : vec) {
            int x = X.F, cnt = X.S;

            int cpy = p;

            while (cpy % x == 0) cpy /= x;

            for (int i = 0; i < cnt - 1; i++) cpy *= x;

            ans = max(ans, cpy);
        }

        cout << ans << '\n';
    }
}