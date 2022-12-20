#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int t[N], l1[N], r1[N], r2[N], l2[N];
vector <pair<int, int> > v;
set <pair<int, int> > s1, s2;

int main() {
    int i, j, k, n, top1 = 0, top2 = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        v.push_back({j, i});
    }
    sort(v.begin(), v.end());
    top1 = 0;
    top2 = 1;
    l2[1] = 1;
    r2[1] = n;
    s2.insert({n, 1});
    int ans = 0,cnt = 0, mn = -1;
    for (i = 0; i < v.size(); ++i) {
        set <pair<int, int> > :: iterator it = s2.lower_bound({v[i].second, 0});
        int p = (*it).second;
        s2.erase(it);
        int lx = v[i].second;
        int rx = v[i].second;
        if (r2[p] == l2[p]) {
            it = s1.lower_bound({r2[p], 0});
            if (it != s1.end()) {
                rx = r1[(*it).second];
                --t[r1[(*it).second] - l1[(*it).second]];
                s1.erase(it);
                it = s1.lower_bound({r2[p], 0});
                --cnt;
            }
            if (it != s1.begin()) {
                --it;
                lx = l1[(*it).second];
                --t[r1[(*it).second] - l1[(*it).second]];
                s1.erase(it);
                --cnt;
            }
        } else if (v[i].second == r2[p]) {
                it = s1.lower_bound({r2[p], 0});
                if (it != s1.end()) {
                    rx = r1[(*it).second];
                    --t[r1[(*it).second] - l1[(*it).second]];
                    s1.erase(it);
                    --cnt;
                }
                --r2[p];
                s2.insert({r2[p], p});
            } else if (v[i].second == l2[p]) {
                    it = s1.lower_bound({r2[p], 0});
                    if (it != s1.begin()) {
                        --it;
                        lx = l1[(*it).second];
                        --t[r1[(*it).second] - l1[(*it).second]];
                        s1.erase(it);
                        --cnt;
                    }
                    ++l2[p];
                    s2.insert({r2[p], p});
                } else {
                    ++top2;
                    r2[top2] = r2[p];
                    l2[top2] = v[i].second + 1;
                    s2.insert({r2[top2], top2});
                    r2[p] = v[i].second - 1;
                    s2.insert({r2[p], p});
                }

        ++top1;
        l1[top1] = lx;
        r1[top1] = rx;
        ++t[rx - lx];
        s1.insert({r1[top1], top1});
        ++cnt;
        if (cnt > ans && t[rx - lx] == cnt) {
            ans = cnt;
            mn = v[i].first;
        }
    }
    cout << mn + 1;
}