#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = -1;
const int inf = 1e9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);

    int c, hr, hb, wr, wb;
    while (cin >> c >> hr >> hb >> wr >> wb) {
        if (wb < wr) {
            swap(hb, hr);
            swap(wb, wr);
        }
        ll ans = 0;
        if (wb >= 100) {
            for (int i = 0; i <= c / wb; i++) {
                ans = max(ans, 1LL * i * hb + 1LL * (c - 1LL * i * wb) / wr * hr);
            }
        } else {
            int O = 30000;
            vector<ll> dp(O, 0);
            for (int i = 0; i < O; i++) {
                if (i + wb < O) {
                    dp[i + wb] = max(dp[i + wb], dp[i] + hb);
                }
                if (i + wr < O) {
                    dp[i + wr] = max(dp[i + wr], dp[i] + hr);
                }
            }
            for (int i = 1; i < O; i++) dp[i] = max(dp[i], dp[i - 1]);
            int ch, cw;
            if (1LL * hr * wb >= 1LL * hb * wr) {
                ch = hr;
                cw = wr;
            } else {
                ch = hb;
                cw = wb;
            }
            int cnt = max(0, (c - 20000) / cw);
            ans += 1LL * cnt * ch;
            c -= 1LL * cnt * cw;
            ans += dp[c];
        }
        cout << ans << endl;
    }

	return 0;
}