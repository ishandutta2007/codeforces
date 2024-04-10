#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    vector<int> a(s.size() + 1, 0), b(s.size() + 1, 0);
    for (int i = 0; i < (int)s.size(); i++) {
        a[i+1] = a[i] + (s[i] == 'a');
        b[i+1] = b[i] + (s[i] == 'b');
    }

    int m = 0;
    for (int i = 0; i < (int)(s.size()); i++) {
        for (int j = i; j <= (int)s.size(); j++) {
            int x = a[i] - a[0] + b[j] - b[i] + a[s.size()] - a[j];
            m = max(m, x);
        }
    }
    cout << m << endl;
}