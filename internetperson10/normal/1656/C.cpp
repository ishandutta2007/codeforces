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
        set<int> s;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int g;
            cin >> g;
            s.insert(g);
        }
        if(s.count(1)) {
            bool ok = true;
            for(int g : s) {
                if(s.count(g+1)) ok = false;
            }
            if(ok) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
        }
    }
}