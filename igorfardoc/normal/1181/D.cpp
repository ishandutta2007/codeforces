#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[maxn * 4 + 7];

void update(int now, int l, int r, int pos) {
    ++t[now];
    if(l == r) return;
    int mid = (l + r) / 2;
    if(mid >= pos) {
        update(now * 2, l, mid, pos);
    } else {
        update(now * 2 + 1, mid + 1, r, pos);
    }
}
int get_pos(int now, int l, int r, int val) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(t[now * 2] > val) {
        return get_pos(now * 2, l, mid, val);
    } else {
        return get_pos(now * 2 + 1, mid + 1, r, val - t[now * 2]);
    }
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> a(m, {0, 0});
    for(int i = 0; i < n; i++) {
        int b;
        cin >> b;
        --b;
        ++a[b].first;
    }
    for(int i = 0; i < m; i++) {
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<pair<ll, int>> qu(q);
    for(int i = 0; i < q; i++) {
        cin >> qu[i].first;
        qu[i].first -= n;
        qu[i].second = i;
    }
    sort(qu.begin(), qu.end());
    int now = 0;
    vi ans(q);
    int i = 0;
    ll curr = 0;
    while(i < m) {
        int st = i;
        while(i < m && a[i].first == a[st].first) {
            update(1, 0, m - 1, a[i].second);
            ++i;
        }
        --i;
        int am = i + 1;
        ll can;
        if(i == m - 1) {
            can = 2e18;
        } else {
            can = (ll)(a[i + 1].first - a[i].first) * am;
        }
        while(now < q && qu[now].first <= can + curr) {
            int id1 = (qu[now].first - curr - 1) % am;
            ans[qu[now].second] = get_pos(1, 0, m - 1, id1);
            ++now;
        }
        curr += can;
        ++i;
    }
    for(const auto& el : ans) {
        cout << el + 1 << '\n';
    }


}