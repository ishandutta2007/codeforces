#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int n;
int mx[200001], sz[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int to = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> sz[i];
        for (int j = 0; j < sz[i]; ++j) {
            int x;
            cin >> x;
            mx[i] = max(mx[i], x);
        }
        to = max(to, mx[i]);
    }
    llong ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (llong)sz[i] * (to - mx[i]);
    }
    printf("%lld\n", ans);
    return 0;
}