#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*
 
















*

 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s;
        for(int i = 1; i <= n; i++) {
            s.insert(i);
        }
        vector<int> v;
        for(int i = 1; i <= n; i++) {
            if(s.count(i) == 0) continue;
            for(int j = i; j <= n; j *= 2) {
                v.push_back(j);
                s.erase(j);
            }
        }
        cout << 2 << '\n';
        for(int g : v) cout << g << ' ';
        cout << '\n';
    }
}