#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto& x : a)
        cin >> x;
    vector<long long> b(n);
    for (auto& x : b)
        cin >> x;
    

    auto possible = [&](long long x) {
        using li = pair<long long, int>;
        priority_queue<li, vector<li>, greater<li>> pq;
        vector<long long> a_copy = a;
        for (int i = 0; i < n; i++) {
            // problem = a - t*b < 0
            //           a < t * b
            //           a / b < t
            long long break_time = a_copy[i] / b[i] + 1;
            if (break_time < k)
                pq.push({break_time, i});
        }

        for (int t = 0; t < k && !pq.empty(); t++) {
            auto [break_time, i] = pq.top();
            pq.pop();
            if (break_time <= t) {
                return false;
            }
            if (a_copy[i] < std::numeric_limits<long long>::max() / 2) {
                a_copy[i] += x;
            }
            long long break_time2 = a_copy[i] / b[i] + 1;
            if (break_time2 < k)
                pq.push({break_time2, i});
        }

        return true;
    };
    
    long long L = -1; // not possible
    long long R = std::numeric_limits<long long>::max() / 2; // possible

    if (!possible(R)) {
        cout << -1 << '\n';
        return 0;
    }

    while (L + 1 != R) {
        long long M = (L + R) / 2;
        if (possible(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << endl;
}