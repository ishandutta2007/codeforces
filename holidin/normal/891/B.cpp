#include <bits/stdc++.h>
using namespace std;
const int N = 300;

int b[N];

int main() {
    int i, j, a[N], n;
    vector <pair<int, int> > v;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    bool found = false;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    v.push_back(v[0]);
    for (i = 0; i < v.size() - 1; ++i)
        b[v[i + 1].second] = v[i].first;
    for (i = 0; i < n; ++i)
        cout << b[i] << ' ';
}