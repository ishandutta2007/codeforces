#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    deque<int> alarms(v.begin(), v.end());
    
    deque<int> cur;
    int needed = 0;
    for (auto i = 0; i < alarms.back() + 1; i++) {
        if (cur.size() && cur.front() == i - m) {
            cur.pop_front();
        }
        if (alarms.size() && alarms.front() == i) {
            cur.push_back(alarms.front());
            alarms.pop_front();
        }
        if ((int)cur.size() == k) {
            needed++;
            cur.pop_back();
        }
    }
    cout << needed << endl;
}