#include<bits/stdc++.h>

using namespace std;

const int N = 200022;
int a[N], cnt[N], pref[N], n, ans = 0;
vector<int> gist[N];
set<int> pos;

void solve(const vector<int>& b, int y) {
    int tmp = 0;
    map<int, int> was;
    for (auto i : b) {
        {
            int sum = pref[i] - tmp;
            if (was.find(sum) == was.end()) {
                int j = -1;
                auto it = pos.lower_bound(i);
                if (it != pos.begin()) {
                    j = *--it;
                }
                was[sum] = j;
            }
        }
        tmp += (a[i] == y);
        {
            int sum = pref[i + 1] - tmp;
            if (was.find(sum) != was.end()) {
                int j = n;
                auto it = pos.lower_bound(i + 1);
                if (it != pos.end()) {
                    j = *it;
                }
                ans = max(ans, j - 1 - was[sum]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        gist[a[i]].push_back(i);
    }
    int x = max_element(cnt, cnt + n) - cnt;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (a[i] == x);
    }
    for (auto x : gist[x]) {
        pos.insert(x);
    }
    for (int y = 0; y < n; y++) {
        if (x == y || (int) gist[y].size() == 0) {
            continue;
        }
        vector<int> b;
        for (auto i : gist[y]) {
            {
                auto it = pos.lower_bound(i);
                if (it != pos.end()) {
                    b.push_back(*it);
                    pos.erase(it);
                }
            }
            {
                auto it = pos.lower_bound(i);
                if (it != pos.begin()) {
                    it = prev(it);
                    b.push_back(*it);
                    pos.erase(it);
                }
            }
        }
        for (auto i : gist[y]) {
            b.push_back(i);
        }
        for (auto i : b) {
            pos.insert(i);
        }
        sort(b.begin(), b.end());
        solve(b, y);
        for (auto i : gist[y]) {
            pos.erase(i);
        }
    }
    cout << ans;
}