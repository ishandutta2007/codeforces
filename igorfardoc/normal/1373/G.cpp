#include<bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll t[2000000], lp[2000000];

void update(int now, int l, int r, int l1, int r1, int val) {
    if(l > r1 || l1 > r) {
        return;
    }
    if(l1 <= l && r <= r1) {
        t[now] += val;
        lp[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
    t[now] = min(t[now * 2], t[now * 2 + 1]) + lp[now];
}
ll get_min(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) {
        return INF;
    }
    if(l1 <= l && r <= r1) {
        return t[now];
    }
    int mid = (l + r) / 2;
    return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1)) + lp[now];
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
    int n, k, m;
    cin >> n >> k >> m;
    --k;
    int delta = n - 1;
    int max1 = delta + n - 1;
    for(int i = -n + 1; i < n; i++) {
        update(1, 0, max1, i + delta, i + delta, i + 1);
    }
    multiset<pair<int, int>> s1;
    multiset<int> s2;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        int val;
        if(x <= k) {
            val = x - k + (n - 1 - y);
        } else {
            val = k - x + (n - 1 - y);
        }
        auto it = s1.find({x, y});
        if(it != s1.end()) {
            s1.erase(it);
            s2.erase(s2.find(val));
            update(1, 0, max1, val + delta, max1, 1);
        } else {
            s1.insert({x, y});
            s2.insert(val);
            update(1, 0, max1, val + delta, max1, -1);
        }
        if(s2.empty()) {
            cout << 0 << '\n';
        } else {
            int min1 = *(s2.begin());
            ll res = get_min(1, 0, max1, min1 + delta, max1);
            //cout << "Res:" << res << endl;
            if(res >= 0) {
                cout << 0 << '\n';
            } else {
                cout << -res << '\n';
            }
        }
    }
}