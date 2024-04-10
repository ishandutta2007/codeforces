#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int t, n;
int q[MAXN], p[MAXN], bio[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) bio[i] = 0;
        bool moze = 1;
        for (int i = 1; i <= n; i++) {
            cin >> q[i];
            if (q[i] < i) moze = 0;
            if (q[i] > q[i - 1]) p[i] = q[i], bio[q[i]] = 1; else p[i] = 0;
        }
        if (!moze) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = n; i >= 1; i--) if (bio[i] == 0) v.push_back(i);
        for (int i = 1; i <= n; i++) {
            if (p[i]) {
                cout << p[i] << " ";
            } else {
                cout << v.back() << " ";
                v.pop_back();
            }
        }
        cout << '\n';
    }
    return 0;
}