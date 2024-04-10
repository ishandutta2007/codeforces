#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long cnt[10001] = {0};
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }

    long long result = 0;
    if (k == 0) {
        for (int i = 0; i < 10001; i++) {
            result += cnt[i]*(cnt[i]-1)/2;
        }
    } else {
        for (int i = 0; i < 10001; i++) {
            for (int j = i; j < 10001; j++) {
                if (__builtin_popcount(i^j) == k)
                    result += cnt[i]*cnt[j];
            }
        }
    }

    cout << result << endl;
}