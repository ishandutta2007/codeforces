#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x == 1) {
                v.push_back(1);
            } else {
                while (v.back() + 1 != x) v.pop_back();
                v.pop_back();
                v.push_back(x);
            }
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i + 1 < v.size()) cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}