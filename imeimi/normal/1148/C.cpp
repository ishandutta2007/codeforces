#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n;
int P[300001];
int R[300001];
vector<pii> ans;

void change(int i, int j) {
    ans.emplace_back(i, j);
    swap(R[P[i]], R[P[j]]);
    swap(P[i], P[j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
        R[P[i]] = i;
    }
    int h = (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        if (P[i] == i) continue;
        int j = R[i];
        if (h <= abs(j - i)) {
            change(i, j);
            continue;
        }
        if (h <= abs(j - n)) {
            change(j, n);
            change(i, n);
            continue;
        }
        if (h <= abs(i - 1)) {
            change(1, j);
            change(1, i);
            change(1, j);
            continue;
        }
        change(1, j);
        change(1, n);
        change(i, n);
        change(1, j);
    }
    printf("%u\n", ans.size());
    for (pii i : ans) printf("%d %d\n", i.fs, i.se);
    return 0;
}