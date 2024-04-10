#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); ++i)

void solve() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    int x;
    forn(i, n) {
        cin >> x;
        q.push(x);
    }
    if (n%2 == 0) q.push(0);
    long long res = 0;
    while (q.size() > 1) {
        long long t = 0;
        forn(i, 3) {
            t += q.top();
            q.pop();
        }
        res += t;
        q.push(t);
    }
    cout << res << endl;
}

int main() {
    solve();
}