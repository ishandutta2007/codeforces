#include <bits/stdc++.h>

using namespace std;

const int maxw = 1e6 + 1;

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> cnt(maxw, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }

    vector<int> result(maxw, 0);
    for (int i = 2; i < maxw; i++) {
        result[i] = cnt[i] + cnt[1];
    }
    for (int i = 2; i < maxw; i++) {
        int v = result[i];
        for (int j = i * 2; j < maxw; j += i) {
            result[j] = max(result[j], v + cnt[j]);
        }
    }

    int answer = cnt[1];
    for (int i = 2; i < maxw; i++) {
        answer = max(answer, result[i]);
    }

    cout << answer << '\n';
}