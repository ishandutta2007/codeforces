#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, cnt[2000000];
    scanf("%d",&n);
    for (int i = 0; i < 2000000; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&t);
        cnt[t]++;
    }
    long long ans = 0;
    for (int i = 0; i < 2000000 - 1; ++i) {
        cnt[i+1] += cnt[i]/2;
        if (cnt[i] % 2) ++ans;
    }
    cout << ans << endl;
}