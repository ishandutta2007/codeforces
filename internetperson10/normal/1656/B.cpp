#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll target;
        cin >> target;
        set<int> s;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        bool ok = false;
        for(int g : s) {
            if(s.count(g + target)) {
                ok = true;
            }
        }
        if(ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}