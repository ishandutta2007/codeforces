#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 101;

int n;
vector<pint> L, M;
void answer(int x, int r, int c) {
    cout << x << ' ' << r + 1 << ' ' << c + 1 << endl;
}
void solve(int x) {
    if (x == 1) {
        if (!M.empty()) answer(2, M.back().va, M.back().vb), M.pop_back();
        else answer(3, L.back().va, L.back().vb), L.pop_back();
    }
    else {
        if (!L.empty()) answer(1, L.back().va, L.back().vb), L.pop_back();
        else answer(5 - x, M.back().va, M.back().vb), M.pop_back();
    }
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) (i + j & 1 ? L : M).emplace_back(i, j);
    }
    for (int i = 0, x; i < n * n; i++) cin >> x, solve(x);
}