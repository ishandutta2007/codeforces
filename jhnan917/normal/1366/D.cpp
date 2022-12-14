#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 1e7;
int D[M + 5];
int main() {
    for (ll i = 2; i <= M; i++) {
        if (D[i]) continue;
        D[i] = i;
        for (ll j = i * i; j <= M; j += i) {
            if (D[j]) continue;
            D[j] = i;
        }
    }
    vector<pair<int, int>> V;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        int b = D[a];
        while (a % b == 0) a /= b;
        if (a == 1) V.emplace_back(-1, -1);
        else V.emplace_back(a, b);
    }
    for (auto [i, j] : V) printf("%d ", i); printf("\n");
    for (auto [i, j] : V) printf("%d ", j); printf("\n");
}