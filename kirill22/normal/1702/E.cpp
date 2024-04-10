#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<multiset<int>> tmp(n);
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cnt[x]++, cnt[y]++;
            tmp[x].insert(y);
            tmp[y].insert(x);
        }
        vector<int> used(n);
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] != 2 || tmp[i].find(i) != tmp[i].end()) {
                ok = 0;
            }
        }
        for (int i = 0; i < n && ok; i++) {
            if (used[i]) {
                continue;
            }
            int x = i, y = i;
            do {
                if (tmp[x].size() == 0) {
                    ok = 0;
                    break;
                }
                int x2 = *tmp[x].begin();
                tmp[x].erase(tmp[x].begin());
                tmp[x2].erase(tmp[x2].find(x));
                if (tmp[y].size() == 0) {
                    ok = 0;
                    break;
                }
                //cout << x << " " << y << endl;
                int y2 = *tmp[y].begin();
                tmp[y].erase(tmp[y].begin());
                tmp[y2].erase(tmp[y2].find(y));
                used[x] = 1;
                used[y] = 1;
                x = x2, y = y2;
            } while (x != y);
            used[x] = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}