#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 4e5;
int arr[MAXN];
int hlef[MAXN], hrig[MAXN];
int lef[MAXN], rig[MAXN];
int glef[MAXN], grig[MAXN];

main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        fill(hlef, hlef + n + 1, 0);
        fill(hrig, hrig + n + 1, 0);
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (hlef[x] == 0) {
                hlef[x] = i + 1;
                arr.push_back(x);
            }
            hrig[x] = i + 1;
        }
        sort(arr.begin(), arr.end());
        int k = arr.size();
        for (int i = 0; i < k; ++i) {
            lef[i] = hlef[arr[i]];
            rig[i] = hrig[arr[i]];
        }
        grig[k - 1] = 0;
        for (int i = k - 2; i >= 0; --i) {
            if (rig[i] < lef[i + 1]) {
                grig[i] = grig[i + 1] + 1;
            } else {
                grig[i] = 0;
            }
        }
        glef[0] = 0;
        for (int i = 1; i < k; ++i) {
            if (lef[i] > rig[i - 1]) {
                glef[i] = glef[i - 1] + 1;
            } else {
                glef[i] = 0;
            }
        }
        int ans = k - 1;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, k - 1 - glef[i] - grig[i]);
        }
        cout << ans << endl;
    }
    return 0;
}