#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    map<long long, int> begin, end;
    set<long long> events;
    for (int i = 0; i < n; i++) {
        begin[v[i].first]++;
        end[v[i].second]++;
        events.insert(v[i].first);
        events.insert(v[i].second);
    }
    
    long long last = -1;
    vector<long long> cnt(n+1, 0);
    int cur = 0;
    for (long long event : events) {
        cnt[cur] += last == -1 ? 0 : event - last - 1;
        cur += begin[event];
        cnt[cur]++;
        last = event;
        cur -= end[event];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
    }
    cout << endl;
}