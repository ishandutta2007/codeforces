#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    set<int> idx;
    set<pi> values;
    vector<int> m(q + 1);

    int cnt = 0;
    for (int i = 1; i <= q; ++i) {
        int op;
        cin >> op;

        if (op == 1) {
            ++cnt;
            cin >> m[cnt];
            idx.insert(cnt);
            values.insert({m[cnt], -cnt});
        }
        else if (op == 2) {
            int idxToRemove = *idx.begin();
            cout << idxToRemove << " ";

            idx.erase(idxToRemove);
            values.erase({m[idxToRemove], -idxToRemove});
        }
        else {
            pi valueToRemove = *values.rbegin();
            cout << -valueToRemove.S << " ";

            values.erase(valueToRemove);
            idx.erase(-valueToRemove.S);
        }
    }

    return 0;
}