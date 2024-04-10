#include <bits/stdc++.h>
using namespace std;

int i, j, n, m;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int mxi = 0, mxj = 0, mni = n, mnj = m;
    for (i = 0; i < n; ++i) {
        cin >> s;
        for (j = 0; j < m; ++j)
        if (s[j] == 'B') {
            mxi = max(i, mxi);
            mxj = max(j, mxj);
            mni = min(i, mni);
            mnj = min(j, mnj);
        }
    }
    cout << 1 + (mni + mxi) / 2 << ' ' << 1 + (mnj + mxj) / 2 << endl;
}