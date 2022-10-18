#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b, c, d, start, len;
    cin >> n >> a >> b >> c >> d >> start >> len;
    vector<pair<long long, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    set<long long> times;
    times.insert(0);
    for (auto p : v) {
        times.insert(p.first);
        times.insert(p.first + 1);
    }

    int idx = 0;
    int idx2 = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    long long psum = 0;
    long long psum2 = 0;
    long long psum3 = start;
    for (auto talk_start : times) {
        while (idx2 < n && v[idx2].first < talk_start + len) {
            if (v[idx2].second == 0) {
                psum2 -= d;
            } else {
                psum2 += c;
            }
            pq.push({psum2, v[idx2].first});
            idx2++;
        }
        while (!pq.empty() && pq.top().second < talk_start) {
            pq.pop();
        }
        while (idx < n && v[idx].first < talk_start) {
            if (v[idx].second == 0) {
                psum -= d;
                psum3 -= b;
            } else {
                psum += c;
                psum3 += a;
            }
            if (psum3 < 0) {
                cout << -1 << endl;
                return 0;
            }
            idx++;
        }
        if (pq.empty()) {
            cout << talk_start << endl;
            return 0;
        } else {
            auto m = psum3 + pq.top().first - psum;
            if (m >= 0) {
                cout << talk_start << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}