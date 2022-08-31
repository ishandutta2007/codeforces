#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        m[-v]++;
    }
    int ans = n, prev = -(1<<30);
    for (auto it: m) {
        if (it.first - prev <= k) {
            ans -= it.second;
        }
        prev = it.first;
    }
    printf("%d\n", ans);
}