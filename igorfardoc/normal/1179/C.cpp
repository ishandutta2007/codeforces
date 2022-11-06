#include<bits/stdc++.h>
#define inf 1000000000ll
#define maxn 1000010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll t[maxn * 4 + 7], lp[maxn * 4 + 7];

void update(int now, int l, int r, int l1, int r1, ll val) {
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
    t[now] = max(t[now * 2], t[now * 2 + 1]) + lp[now];
}

int get_id(int now, int l, int r, ll adding=0) {
    if(l == r) {
        if(t[now] + adding > 0) {
            return l;
        }
        return -1;
    }
    int mid = (l + r) / 2;
    adding += lp[now];
    if(adding + t[now * 2 + 1] > 0) {
        return get_id(now * 2 + 1, mid + 1, r, adding);
    }
    return get_id(now * 2, l, mid, adding);
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
    for(int i = 0; i <= maxn; i++) {
        update(1, 0, maxn, i, i, -inf);
    }
    int n, m;
    cin >> n >> m;
    map<int, int> am;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        am[a[i]]++;
        if(am[a[i]] == 1) {
            update(1, 0, maxn, a[i], a[i], inf);
        }
        update(1, 0, maxn, 0, a[i], 1);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        update(1, 0, maxn, 0, b[i], -1);
    }
    int q;
    cin >> q;
    for(int o = 0; o < q; o++) {
        int t, i, x;
        cin >> t >> i >> x;
        --i;
        if(t == 1) {
            update(1, 0, maxn, 0, a[i], -1);
            --am[a[i]];
            if(am[a[i]] == 0) {
                update(1, 0, maxn, a[i], a[i], -inf);
            }
            a[i] = x;
            am[a[i]]++;
            if(am[a[i]] == 1) {
                update(1, 0, maxn, a[i], a[i], inf);
            }
            update(1, 0, maxn, 0, a[i], 1);
        } else {
            update(1, 0, maxn, 0, b[i], 1);
            b[i] = x;
            update(1, 0, maxn, 0, b[i], -1);
        }
        cout << get_id(1, 0, maxn) << '\n';
    }

}