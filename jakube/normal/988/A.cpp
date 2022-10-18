#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x] = i+1;
    }
    if ((int)m.size() >= k) {
        cout << "YES" << '\n';
        int c = 0;
        for (auto p: m) {
            cout << p.second << ' ';
            c++;
            if (c == k)
                break;
        }
        cout << '\n';
        
    } else
        cout << "NO" << '\n';
        
}