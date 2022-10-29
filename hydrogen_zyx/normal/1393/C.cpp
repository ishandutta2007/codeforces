#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n;

bool check(int mid) {
    set<pair<int, int> > s;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            s.insert(pair<int, int>(a[i], i));
        }
    }
    queue<pair<int, pair<int, int> > > que;
    for (int i = 1; i <= n; i++) {
        while (!que.empty() && i - que.front().first > mid) {
            s.insert(pair<int, int>(que.front().second.first,
                                    que.front().second.second));
            que.pop();
        }
        if (s.empty()) return 0;
        set<pair<int, int> >::iterator it = s.end();
        it--;
        if (it->first > 1) {
            que.push(pair<int, pair<int, int> >(
                i, pair<int, int>(it->first - 1, it->second)));
        }
        s.erase(it);
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) a[i] = 0;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            a[num]++;
        }
        int l = 0, r = n - 1, mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }
}