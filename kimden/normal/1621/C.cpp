#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int queries;

int query(int x) {
    ++queries;
    cout << "? " << x + 1 << endl;
    int y;
    cin >> y;
    if (y == 0) {
        exit(0);
    }
    --y;
    return y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queries = 0;
        vector<int> cur;
        vector<int> p(n, -1);
        vector<int> mkd(n, 0);
        for (int i = 0; i < n; ++i) {
            if (mkd[i]) {
                continue;
            }
            cur.clear();
            cur.push_back(query(i));
            while (cur.size() == 1 || cur.back() != cur[0]) {
                cur.push_back(query(i));
            }
            for (int j: cur) {
                mkd[j] = 1;
            }
            for (int j = 0; j + 1 < cur.size(); ++j) {
                p[cur[j]] = cur[j + 1];
            }
        }
        cout << "!";
        for (int i = 0; i < n; ++i) {
            assert(p[i] != -1);
            cout << " " << (p[i] + 1);
        }
        cout << endl;
    }


}