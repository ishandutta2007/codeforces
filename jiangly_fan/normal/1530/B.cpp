#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int h, w;
        cin >> h >> w;
        vector<string> vs(h, string(w, '0'));
        vs[0][0] = vs[0].back() = vs.back()[0] = vs.back().back() = '1';
        for (int i = 2; i + 2 < w; i += 2)
            vs[0][i] = vs.back()[i] = '1';
        for (int i = 2; i + 2 < h; i += 2)
            vs[i][0] = vs[i].back() = '1';
        for (auto s : vs) cout << s << "\n";
        cout << "\n";
    }
    return 0;
}