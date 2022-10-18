#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = { b[i], i };
    }
    sort(v.begin(), v.end());

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        v[i].first = v[i].second;
        v[i].second = a[i];
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i].second << " ";
    cout << endl;
}