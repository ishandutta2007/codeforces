#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i + 2 < n; i++) {
        int mask = 0;
        for (int j = i; j < i + 3; j++) {
            if (s[j] != '.')
                mask |= 1 << (s[j] - 'A');
        }

        if (mask == 7) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}