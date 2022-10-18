#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [](auto s, auto t){ return s.size() < t.size(); });
    

    for (int i = 0; i < n - 1; i++) {
        string a = v[i];
        string b = v[i+1];
        bool f = false;
        for (int j = 0; j + a.size() <= b.size(); j++) {
            if (b.substr(j, a.size()) == a)
                f = true;
        }
        if (!f) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (auto x : v) {
        cout << x << '\n';
    }
}