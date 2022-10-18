#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        sort(x.begin(), x.end());
        auto it = unique(x.begin(), x.end());
        x.resize(it - x.begin());
        s.insert(x);
    }
    cout << (int)s.size() << '\n';
}