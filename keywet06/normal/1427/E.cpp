#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

vector<pair<pair<int64, int64>, char> > ops;

void op(int64 a, char c, int64 b) { ops.push_back({{a, b}, c}); }

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int64 x;
    cin >> x;
    for (int64 j = 0; j < 30; j++) {
        op(x << j, '+', x << j);
    }
    int64 cx = x;
    for (int64 j = 1; j < 25; j++) {
        if (cx & (1ll << j)) {
            op(cx, '^', x << j);
            cx ^= (x << j);
        }
    }
    op(x, '+', cx);
    op(x + cx, '^', cx);
    int64 y = (x + cx) ^ cx;
    op(y, '+', cx);
    op(y + cx, '^', cx);
    int64 z = (y + cx) ^ cx;
    op(x, '^', y);
    op(y, '^', z);
    for (int64 j = 1; j < 30; ++j) op(1ll << j, '+', 1ll << j);

    for (int64 j = 1; j < 30; ++j) {
        if (x & (1ll << j)) {
            op(x, '^', 1ll << j);
            x ^= (1ll << j);
        }
    }
    cout << ops.size() << '\n';
    for (auto e : ops) {
        cout << e.first.first << " " << (char)(e.second) << " "
             << e.first.second << '\n';
    }
}