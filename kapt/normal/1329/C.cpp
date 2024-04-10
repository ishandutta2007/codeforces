#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = (1 << 21) + 10;
int arr[MAXN];
int sarr[MAXN];
int can[MAXN];
int rl[MAXN];
int ind[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int h, g;
        cin >> h >> g;
        int ans = 0;
        vector<int> ansarr;
        fill(arr, arr + (1 << (h + 1)), 0);
        for (int i = 1; i < (1 << h); ++i) {
            rl[i] = i;
            cin >> arr[i];
            ind[arr[i]] = i;
            ans += arr[i];
            sarr[i] = arr[i];
        }
        sort(sarr + 1, sarr + (1 << h));
        fill(can, can + (1 << h), 0);
        for (int i = (1 << h) - 1; i >= 1; --i) {
            int el = sarr[i];
            int v = ind[el];
            if (can[v]) {
                continue;
            }
            ans -= arr[v];
            ansarr.push_back(v);
            while (true) {
                int l = v * 2, r = v * 2 + 1;
                if ((arr[l] == 0 && arr[r] == 0) || l >= (1 << h)) {
                    arr[v] = 0;
                    break;
                }
                if (arr[l] > arr[r]) {
                    arr[v] = arr[l];
                    ind[arr[l]] = v;
                    v = l;
                } else {
                    arr[v] = arr[r];
                    ind[arr[r]] = v;
                    v = r;
                }
            }
            while (v > 1) {
                v /= 2;
                int l = v * 2;
                int r = v * 2 + 1;
                if (arr[l] < arr[r]) {
                    swap(l, r);
                }
                if ((can[l] || arr[l] == 0) && v < (1 << g)) {
                    can[v] = 1;
                }
            }
        }
        cout << ans << '\n';
        for (auto elem : ansarr) {
            cout << elem << " ";
        }
        cout << '\n';
    }
    return 0;
}