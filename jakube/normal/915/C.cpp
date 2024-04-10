#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    
    if (s.size() < t.size()) {
        reverse(s.begin(), s.end());
        cout << s << '\n';
        return 0;
    }

    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            auto tmp = s;
            swap(tmp[i], tmp[j]);
            sort(tmp.begin() + i + 1, tmp.end());
            if (tmp <= t) {
                s = tmp;
                break;
            }
        }
    }
    cout << s << '\n';
}