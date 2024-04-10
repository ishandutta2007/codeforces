#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, k;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        v.clear();
        for (int i = (k + 1) / 2; i <= n; i++) {
            if (i != k) v.push_back(i);
        }
        cout << v.size() << '\n';
        for (auto x : v) cout << x << " "; cout << '\n';
    }
    return 0;
}