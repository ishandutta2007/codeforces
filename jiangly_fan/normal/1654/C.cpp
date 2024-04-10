#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        multiset<LL> ms;
        LL s = 0;
        for (int i = 0; i < n; i += 1) {
            LL a;
            cin >> a;
            ms.insert(a);
            s += a;
        }
        priority_queue<LL> pq;
        pq.push(s);
        while (not pq.empty() and pq.size() <= ms.size()) {
            LL x = pq.top();
            pq.pop();
            if (ms.find(x) != ms.end()) {
                ms.erase(ms.find(x));
                continue;
            }
            pq.push((x + 1) / 2);
            pq.push(x / 2);
        }
        cout << (ms.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}