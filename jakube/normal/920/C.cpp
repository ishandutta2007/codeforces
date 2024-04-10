#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    
    int last = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0')
            last = i + 1;
        if (s[i] == '1' && (i + 1 == n - 1 || s[i+1] == '0'))
            sort(v.begin() + last, v.begin() + i + 2);
    }
    if (is_sorted(v.begin(), v.end())) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}