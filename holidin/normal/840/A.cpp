#include <bits/stdc++.h>
using namespace std;
const int N = 300000;

int main() {
    vector <int> v;
    vector <pair<int, int> > m;
    int i, j, d[N], n;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        v.push_back(j);
    }
    for (i = 1; i <= n; ++i) {
        cin >> j;
        m.push_back(make_pair(-j, i));
    }
    sort(v.begin(), v.end());
    sort(m.begin(), m.end());
    for (i = 0; i < n; ++i)
        d[m[i].second] = v[i];
    for (i = 1; i <= n; ++i)
        cout << d[i] << ' ';
}