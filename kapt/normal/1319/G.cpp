#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5, B = 3, MOD = 1791791791;
int power[MAXN], pref[MAXN];

bool hasher(int i, int j, int len) {
    int h1 = pref[i + len] - pref[i] * power[len];
    int h2 = pref[j + len] - pref[j] * power[len];
    return (h1 - h2) % MOD == 0;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> nls;
    vector<int> odd;
    odd.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            odd.push_back(0);
            nls.push_back(i);
        } else {
            odd[odd.size() - 1] ^= 1;
        }
    }
    power[0] = 1;
    for (int i = 0; i < odd.size(); ++i) {
        power[i + 1] = (power[i] * B) % MOD;
        pref[i + 1] = (pref[i] * B + odd[i] + 1) % MOD;
    }
    int q;
    cin >> q;
    while (q--) {
        int s1, s2, len;
        cin >> s1 >> s2 >> len;
        s1--; s2--;
        int l1 = lower_bound(nls.begin(), nls.end(), s1) - nls.begin();
        int r1 = lower_bound(nls.begin(), nls.end(), s1 + len) - nls.begin();
        int l2 = lower_bound(nls.begin(), nls.end(), s2) - nls.begin();
        int r2 = lower_bound(nls.begin(), nls.end(), s2 + len) - nls.begin();
        int cnt1, cnt2;
        cnt1 = r1 - l1;
        cnt2 = r2 - l2;
        if (cnt1 != cnt2) {
            cout << "No\n";
            continue;
        }
        if (cnt1 == 0) {
            cout << "Yes\n";
            continue;
        }
        if (((nls[l1] - s1) - (nls[l2] - s2)) % 2 != 0) {
            cout << "No\n";
            continue;
        }
        if (((nls[r1 - 1] - s1) - (nls[r2 - 1] - s2)) % 2 != 0) {
            cout << "No\n";
            continue;
        }
        if (hasher(l1 + 1, l2 + 1, cnt1 - 1)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}