#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int idx = 0; idx < n; idx++)
        cin >> a[idx];
    vector<int> b(w);
    for (int idx = 0; idx < w; idx++)
        cin >> b[idx];
    
    vector<int> pattern;
    for (int i = 1; i < w; i++) {
        pattern.push_back(b[i]-b[i-1]);
    }

    pattern.push_back(numeric_limits<int>::max());
    for (int i = 1; i < n; i++) {
        pattern.push_back(a[i]-a[i-1]);
    }

    if (w == 1) {
        cout << n << endl;
        return 0;
    }

    vector<int> p(pattern.size(), 0);
    int border = 0;
    int cnt = 0;
    for (int i = 1; i < pattern.size(); i++) {
        while (border > 0 && pattern[border] != pattern[i]) {
            border = p[border-1];
        }
        border += pattern[border] == pattern[i];
        p[i] = border;
        if (border == w-1)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}