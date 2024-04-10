#include <bits/stdc++.h>
const int N = 1e5 + 6;
int cnt, n, k;
int a[N];
long long ans;
long long f[N];
std::vector<int> vector;
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    f[n - 1] = 1;
    ans = 1;
    vector.push_back(n - 1);
    for (int i = n - 2; i; --i) {
        k = *(std::upper_bound(vector.rbegin(), vector.rend(), a[i]) - 1);
        ans += f[i] = f[k] + (k - i) + (n - a[i]);
        while (vector.size() && a[i] >= a[vector[vector.size() - 1]]) {
            vector.pop_back();
        }
        vector.push_back(i);
    }
    printf("%lld\n", ans);
    return 0;
}