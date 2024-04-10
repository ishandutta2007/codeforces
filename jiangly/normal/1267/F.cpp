#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;
    if (k1 > m - 1 || k2 > n - 1) {
        cout << "No\n";
        return 0;
    }
    vector<int> a(k1), b(k2);
    for (int i = 0; i < k1; ++i)
        cin >> a[i];
    for (int i = 0; i < k2; ++i) 
        cin >> b[i];
    while (a.size() < m - 1)
        a.push_back(a.back());
    while (b.size() < n - 1)
        b.push_back(b.back());
    cout << "Yes\n";
    multiset<int> prufer;
    priority_queue<int, vector<int>, greater<int>> unused;
    for (int i : a)
        prufer.insert(i);
    for (int i : b)
        prufer.insert(i);
    for (int i = 1; i <= n + m; ++i)
        if (prufer.find(i) == prufer.end())
            unused.push(i);
    k1 = k2 = 0;
    for (int i = 0; i < n + m - 2; ++i) {
        int x = unused.top(), y;
        unused.pop();
        if (x <= n)
            y = b[k2++];
        else
            y = a[k1++];
        cout << x << " " << y << "\n";
        prufer.erase(prufer.find(y));
        if (prufer.find(y) == prufer.end())
            unused.push(y);
    }
    int x = unused.top();
    unused.pop();
    int y = unused.top();
    cout << x << " " << y << "\n";
    return 0;
}