#include <bits/stdc++.h>
using namespace std;

const int K= 100, MAXN = 1e5;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int used[2 * MAXN];
int cnt[2 * MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>> n;
    vector<int64_t> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    gp_hash_table<int64_t, int> gp;
    int mx = 0;
    for (int i = -K; i <= K; ++i) {
        gp.clear();
        for (int j = 0; j <n; ++j) {
            gp[arr[j] - (int64_t)i* j]++;
            mx= max(mx, gp[arr[j] - (int64_t)i * j]);
        }
    }
    gp.clear();
    int cur = 0;
    for (int i= 0; i < n; ++i) {
        cur++;
        for (int j = i + 1;j < min(n, i + MAXN / K); ++j) {
            if (i == j) continue;
            if ((arr[i] - arr[j]) % (i - j) != 0) continue;
            int d = (arr[i] - arr[j]) / (i - j) + MAXN;
            if (used[d] == cur) {
                cnt[d]++;
            } else {
                cnt[d] = 2;
                used[d] = cur;
            }
            if (cnt[d] > mx) mx = cnt[d];
        }
    }
    cout<<n - mx;
    return 0;
}