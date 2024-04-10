#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 300100;

int n;

int64 p[N];

priority_queue<int64> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (!q.empty() && -q.top() < p[i]) {
            ans += p[i] + q.top();
            q.pop(), q.push(-p[i]), q.push(-p[i]);
        } else {
            q.push(-p[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}