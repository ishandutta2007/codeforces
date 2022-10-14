#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
map <int, llint> mp;
llint sol;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mp.clear();
        sol = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            sol += (n - i + 1) * mp[x];
            mp[x] += i;
        }
        cout << sol << '\n';
    }
    return 0;
}