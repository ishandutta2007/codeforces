#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(m), p(m);
    for (int i = 0; i < m; i += 1) {
        string s(m, '0');
        s[i] = '1';
        cout << "? " << s << endl;
        cin >> v[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int x, int y){
        return v[x] < v[y];
    });
    string s(m, '0');
    int ans = 0;
    for (int i : p) {
        s[i] = '1';
        int cur = 0;
        cout << "? " << s << endl;
        cin >> cur;
        if (cur - ans == v[i]) ans = cur;
        else s[i] = '0';
    }
    cout << "! " << ans << endl;
    return 0;
}