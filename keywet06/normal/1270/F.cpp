#include <bits/stdc++.h>

using namespace std;

const int LIM = 200;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    long long ans = 0;
    for (int i = 1; i <= LIM; ++i) {
        vector<long long> a(n + 1);
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            ++sum;
            if (s[j] == '1') sum -= i;
            a[j + 1] = sum;
        }
        sort(a.begin(), a.end());
        for (int l = 0; l <= n;) {
            int r = l;
            while (r <= n && a[l] == a[r]) ++r;
            ans += 1LL * (r - l) * (r - l - 1) / 2;
            l = r;
        }
    }
    vector<int> p;
    for (int i = 0; i < n; ++i)
        if (s[i] == '1') p.push_back(i);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < p.size() && p[j] < i) ++j;
        for (int k = j; k < p.size() && (k - j + 1) * LIM <= n; ++k) {
            int l = p[k] - i + 1, r = (k == p.size() - 1 ? n : p[k + 1]) - i;
            l = (l + k - j) / (k - j + 1);
            r = r / (k - j + 1);
            ans += max(0, r - max(LIM + 1, l) + 1);
        }
    }
    cout << ans << "\n";
    return 0;
}