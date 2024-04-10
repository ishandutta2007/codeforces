#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        --a[i];
    }
    set<int> s;
    for (int i = 0; i < n; ++i)
        s.insert(i);
    cout << a[0] + 1 << "\n";
    s.erase(a[0]);
    for (int i = 0; i < n - 1; ) {
        int u = a[i];
        int v = *s.rbegin();
        s.erase(v);
        int j = i + 1;
        while (j < n - 1 && s.find(a[j]) != s.end()) {
            cout << u + 1 << " " << a[j] + 1 << "\n";
            u = a[j];
            s.erase(u);
            ++j;
        }
        i = j;
        cout << u + 1 << " " << v + 1 << "\n";
    }
    return 0;
}