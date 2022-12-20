#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

int a[N];
vector <int> e[N];
bool b[N];

int main() {
    int i, j, n, s, x, y;
    vector <int> v;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int tk = -1;
    set <int> p;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    if (a[0] != 1) {
        cout << "No";
        return 0;
    }
    for (i = 0; i < n; ++i) {
        while (p.size() == 0 && tk < n) {
            ++tk;
            for (j = 0; j < e[a[tk]].size(); ++j)
            if (!b[e[a[tk]][j]])
                p.insert(e[a[tk]][j]);
        }
        if (b[a[i]]) {
            cout << "No";
            return 0;
        }
        b[a[i]] = true;
        if (i != 0) {
            if (p.find(a[i]) == p.end()) {
                cout << "No";
                return 0;
            }
            p.erase(a[i]);
        }
    }
    cout << "Yes";

}