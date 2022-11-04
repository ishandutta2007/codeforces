#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi t(4000009, 0);

void update(int now, int l, int r, int pos, int val) {
    if(l == r) {
        t[now] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) {
        update(now * 2, l, mid, pos, val);
    } else {
        update(now * 2 + 1, mid + 1, r, pos, val);
    }
    t[now] = t[now * 2] + t[now * 2 + 1];
}

int get_sum(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) {
        return 0;
    }
    if(l1 <= l && r <= r1) {
        return t[now];
    }
    int mid = (l + r) / 2;
    return get_sum(now * 2, l, mid, l1, r1) + get_sum(now * 2 + 1, mid + 1, r, l1, r1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<pair<char, pair<int, int>>>> ev(1000001);
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        if(rx == 1000000 && lx == 0) {
            ++ans;
        }
        ev[lx].push_back({'a', {y, 1}});
        ev[rx].push_back({'d', {y, 0}});
    }
    for(int i = 0; i < m; i++) {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        if(ry == 1000000 && ly == 0) {
            ++ans;
        }
        ev[x].push_back({'?', {ly, ry}});
    }
    for(int i = 0; i <= 1000000; i++) {
        for(const auto& e : ev[i]) {
            if(e.first != 'a') {
                continue;
            }
            update(1, 0, 1000000, e.second.first, e.second.second);
        }
        for(const auto& e : ev[i]) {
            if(e.first != '?') {
                continue;
            }
            int here = get_sum(1, 0, 1000000, e.second.first, e.second.second);
            /*if(e.second.first == 0 && e.second.second == 1000000) {
                here *= 2;
            }*/
            ans += here;
        }
        for(const auto& e : ev[i]) {
            if(e.first != 'd') {
                continue;
            }
            update(1, 0, 1000000, e.second.first, 0);
        }
    }
    cout << ans;
}