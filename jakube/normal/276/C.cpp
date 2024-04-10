#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l - 1]++;
        if (r < n) cnt[r]--;
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i-1];
    }

    sort(cnt.begin(), cnt.end());
    sort(v.begin(), v.end());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += (long long)cnt[i] * v[i];
    }
    cout << result << endl;
}