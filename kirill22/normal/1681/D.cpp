#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    map<long long, int> dist;
    dist[x] = 0;
    set<pair<int, long long>> st;
    st.insert({0, x});
    while (st.size()) {
        auto [d, x] = *st.begin();
        st.erase(st.begin());
        string s = to_string(x);
        if (s.size() >= n) {
            cout << dist[x];
            return 0;
        }
        for (auto c : s) {
            long long y = x * (c - '0');
            string s2 = to_string(y);
            if (dist.find(y) == dist.end() || dist[y] > dist[x] + 1) {
                st.erase({dist[y] - (int) s2.size(), y});
                dist[y] = dist[x] + 1;
                st.insert({dist[y] - (int) s2.size(), y});
            }
        }
    }
    cout << -1;
}