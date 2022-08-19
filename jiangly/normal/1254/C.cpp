#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL area[1001];
int sign(int i, int j, int k) {
    cout << 2 << " " << i << " " << j << " " << k << endl;
    int result;
    cin >> result;
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int v;
    if (sign(1, 2, 3) > 0)
        v = 2;
    else
        v = 3;
    for (int i = 4; i <= n; ++i)
        if (sign(1, i, v) > 0)
            v = i;
    vector<int> l, r;
    vector<int> x;
    for (int i = 2; i <= n; ++i) {
        if (i == v)
            continue;
        x.push_back(i);
        cout << 1 << " " << i << " " << v << " " << 1 << endl;
        cin >> area[i];
    }
    sort(x.begin(), x.end(), [&](int i, int j) {return area[i] < area[j];});
    for (int i = 0; i < n - 3; ++i) {
        if (sign(1, x[i], x[i + 1]) > 0)
            r.push_back(x[i]);
        else
            l.push_back(x[i]);
    }
    r.push_back(x.back());
    cout << 0 << " " << 1 << " " << v;
    for (int v : r)
        cout << " " << v;
    reverse(l.begin(), l.end());
    for (int v : l)
        cout << " " << v;
    cout << endl;
    return 0;
}