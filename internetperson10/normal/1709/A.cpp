#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int x;
    cin >> x;
    set<int> s;
    int v[4];
    v[0] = 0;
    cin >> v[1] >> v[2] >> v[3];
    s.insert(x);
    for(int z = 0; z < 10; z++) {
        for(int g : s) {
            s.insert(v[g]);
        }
    }
    if(s.size() == 4) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}