#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> events;
    for (int idx = 0; idx < n; idx++) {
        int l, r;
        cin >> l >> r;
        events.push_back(make_tuple(l, -r, idx+1));
    }

    sort(events.begin(), events.end());

    priority_queue<pair<int, int>> pq;

    long long ma = 0;
    for (int i = 0; i < n; i++) {
        int l, r, idx;
        tie(l, r, idx) = events[i];
        if (pq.size() == k) {
            pq.pop();
        }
        pq.push({r, idx});
        if (pq.size() == k) {
            ma = max(ma, 1LL - pq.top().first - l);
        }
    }

    while (!pq.empty()) {
        pq.pop();
    }

    if (ma == 0) {
        cout << 0 << endl;
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }


    for (int i = 0; i < n; i++) {
        int l, r, idx;
        tie(l, r, idx) = events[i];
        if (pq.size() == k) {
            pq.pop();
        }
        pq.push({r, idx});
        if (pq.size() == k) {
            if (1LL - pq.top().first - l == ma) {
                cout << ma << endl;
                while (!pq.empty()) {
                    cout << pq.top().second << " ";
                    pq.pop();
                }
                cout << endl;
                return 0;
            }
        }
    }

    return 0;
}