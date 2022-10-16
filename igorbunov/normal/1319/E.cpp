#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

#pragma GCC_OPTIMIZE("ofast")
#pragma target("sse", "sse2", "sse3", "ssse3", "avx")

pair<int, int> t[1000000];

int ARR[200000];

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v].first = ARR[l];
        t[v].second = 0;
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v].first = max(t[v * 2 + 1].first, t[v * 2 + 2].first);
    }
}

void push(int v, int vl, int vr) {
    int val = t[v].second;
    t[v].first += val;
    t[v].second = 0;
    if (vr - vl > 1) {
        t[v * 2 + 1].second += val;
        t[v * 2 + 2].second += val;
    }
}

void update(int v, int l, int r, int vl, int vr, int val) {
    push(v, vl, vr);
    if (l >= r) {
        return;
    }
    if (l == vl && r == vr) {
        t[v].second += val;
        push(v, vl, vr);
        return;
    }

    int vm = (vl + vr) / 2;
    update(v * 2 + 1, l, min(r, vm), vl, vm, val);
    update(v * 2 + 2, max(vm, l), r, vm, vr, val);
    t[v].first = max(t[v * 2 + 1].first, t[v * 2 + 2].first);
}

void print(int v, int l, int r) {
    push(v, l, r);
    if (r - l == 1) {
        cout << t[v].first << " ";
    } else {
        int m = (l + r ) / 2;
        print(v * 2 + 1, l, m);
        print(v * 2 + 2, m, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);

    int min1 = 1000000000;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        min1 = min(min1, a[i].second);
    }
    sort(a.begin(), a.end());

    vector<pair<int, int>> b(m);

    int min2 = 1000000000;
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
        min2 = min(min2, b[i].second);
    }

    sort(b.begin(), b.end());

    vector<pair<int, int>> bn;

    bn.push_back(b[0]);

    for (int i = 1; i < m; i++) {
        if (b[i].first != b[i - 1].first) {
            bn.push_back(b[i]);
        }
    }

    b = bn;
    m = bn.size();

    vector<int> bb(m);
    vector<int> bc(m);

    vector<int> pr(m);


    for (int i = 0; i < m; i++) {
        bb[i] = b[i].first;
        if (i == 0) {
            pr[i] = b[i].second * -1;
            bc[i] = b[i].second * -1;
        } else {
            pr[i] = b[i].second * -1;
            bc[i] = b[i].second * -1 - pr[i - 1];
        }
        ARR[i] = pr[i];
    }


    build(0, 0, m);

    vector<pair<int, pair<int, int>>> monsters(k);

    for (int i = 0; i < k; i++) {
        cin >> monsters[i].first >> monsters[i].second.first >> monsters[i].second.second;
    }

    sort(monsters.begin(), monsters.end());
    int ans = -1 * (min1 + min2);
    int ind = -1;

    for (int i = 0; i < n; i++) {
        int now = a[i].second * -1;
        while (ind + 1 < k && monsters[ind + 1].first < a[i].first) {

            int now_b = monsters[ind + 1].second.first;
            int cost = monsters[ind + 1].second.second;

            if (bb.back() < now_b) {
                ind++;
                continue;
            }

            int l = -1;
            int r = m - 1;

            while (r - l > 1) {
                int m = (l + r) / 2;
                if (bb[m] >= now_b + 1) {
                    r = m;
                } else {
                    l = m;
                }
            }



            int ind_b = r;

            bc[ind_b] += cost;

            update(0, ind_b, m, 0, m, cost);

            ind++;
        }
        push(0, 0, m);
        ans = max(ans, t[0].first + now);
    }

    cout << ans;




    return 0;
}