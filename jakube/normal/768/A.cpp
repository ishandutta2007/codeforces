#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int idx1 = 0;
    while (idx1 < n && v[idx1] == v[0]) idx1++;

    int idx2 = n-1;
    while (idx2 >= idx1 && v[idx2] == v.back()) idx2--;

    cout << (idx2 + 1 - idx1) << endl;
    return 0;
}