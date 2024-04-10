#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<long long, long long>> events;
    for (int i = 0; i < n; ++i) {
        long long l, r, a;
        cin >> l >> r >> a;
        l += a;
        ++r;
        events.emplace_back(l, a);
        events.emplace_back(r, -a);
    }
    sort(events.begin(), events.end());
    multiset<long long> s;
    long long val = 0, len = 1E18;
    for (int i = 0, j; i < events.size(); i = j) {
        j = i;
        while (j < events.size() && events[i].first == events[j].first) {
            long long x = events[j++].second;
            if (x > 0)
                s.insert(x);
            else
                s.erase(s.find(-x));
        }
        if (j == events.size())
            continue;
        auto d = s.empty() ? (long long)1E18 : *s.begin();
        long long g = events[j].first - events[i].first;
        if (len >= d) {
            ++val;
            len = 0;
        }
        long long result = (len + g - 1) % d + 1;
        val += (g - result + len) / d;
        len = result;
    }
    cout << val << endl;
    return 0;
}