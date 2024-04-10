#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int mi = n;
    int p = 0;
    for (int lo = 0; lo < 101; lo++) {
        int sum = 0;
        for (int i = lo + d + 1; i < 101; i++) {
            sum += cnt[i];
        }
        mi = min(mi, p + sum);
        p += cnt[lo];
    }
    cout << mi << endl;
}