#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef pair<int, int> pii;

int n, q;
int C[500001];
vector<pii> P[500001];
int ans[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> C[i];
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        P[r].emplace_back(l, i);
    }
    pii basis[20] = {};
    for (int R = 1; R <= n; ++R) {
        pii v(C[R], R);
        for (int i = 20; i--; ) {
            if (v.fs >> i) {
                if (v.se < basis[i].se) v.fs ^= basis[i].fs;
                else if (basis[i].fs == 0) {
                    basis[i] = v;
                    break;
                }
                else {
                    swap(v, basis[i]);
                    v.fs ^= basis[i].fs;
                }
            }
        }
        for (pii _ : P[R]) {
            int L, idx;
            tie(L, idx) = _;
            int v = 0;
            for (int i = 20; i--; ) {
                if (basis[i].se < L) continue;
                if (((v >> i) & 1) == 0) v ^= basis[i].fs;
            }
            ans[idx] = v;
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}