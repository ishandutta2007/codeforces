#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int q, n;
int P[201];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> P[i];
        }
        bool cw = 1, ccw = 1;
        for (int i = 1; i <= n; ++i) {
            int j = i % n + 1;
            if (P[i] % n + 1 != P[j]) cw = 0;
            if (P[i] != P[j] % n + 1) ccw = 0;
        }
        printf(cw || ccw ? "YES\n" : "NO\n");
    }
    return 0;
}