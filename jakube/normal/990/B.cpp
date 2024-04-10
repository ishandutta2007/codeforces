#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    stack<int> s;
    for (int x : v) {
        while (!s.empty() && s.top() < x && s.top() + K >= x)
            s.pop();
        s.push(x);
    }
    cout << (int)s.size() << '\n';
}