#include <bits/stdc++.h>
using namespace std;
bool query(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    char result;
    cin >> result;
    return result == '>';
}
void solve() {
    int n;
    cin >> n;
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        int x = query(2 * i, 2 * i + 1);
        l.push_back(2 * i + x);
        r.push_back(2 * i + 1 - x);
    }
    sort(l.begin(), l.end(), query);
    r.erase(find(r.begin(), r.end(), l.front() ^ 1));
    sort(r.begin(), r.end(), query);
    for (int i = 0; i < n - 1; ++i)
        query(r[i], l[n - i - 2]);
    cout << "!" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}