#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<long long> v(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                h[i] |= 1LL << j;
                v[j] |= 1LL << i;
            }
        }
    }
    
    bool nice = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((h[i] & h[j]) && h[i] != h[j])
                nice = false;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if ((v[i] & v[j]) && v[i] != v[j])
                nice = false;
        }
    }

    if (nice)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}