#include<bits/stdc++.h>

using namespace std;

struct tree {
    vector<long long> f;

    tree() {}

    void build(int n) {
        f.resize(n);
    }

    void update(int i, int x) {
        while (i < (int) f.size()) {
            f[i] += x;
            i |= (i + 1);
        }
    }

    long long get(int i) {
        long long res = 0;
        while (i >= 0) {
            res += f[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
};

int check(vector<int> a, int x) {
    int n = (int) a.size();
    int pos = 0;
    while (pos < n && a[pos] > x) {
        pos++;
    }
    a.insert(a.begin() + pos, x);
    n++;
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    tree cnt, sum;
    cnt.build(n + 22);
    sum.build(n + 22);
    for (int k = n; k >= 1; k--) {
        long long res = sum.get(k) + (n - k - cnt.get(k)) * 1ll * k;
        if (pref[k] > k * 1ll * (k - 1) + res) {
            //cout << x << " " << pos << " " << k << " " << res << endl;
            if (k - 1 < pos) {
                return -1;
            } else {
                return 1;
            }
        }
        sum.update(a[k - 1], a[k - 1]);
        cnt.update(a[k - 1], 1);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    sort(a.rbegin(), a.rend());
    int l = 0, r = n;
    {
        int vl = -1, vr = n + 1;
        while (vl + 1 < vr) {
            int m = (vl + vr) / 2;
            if (check(a, m) == -1) {
                vl = m;
            } else {
                vr = m;
            }
        }
        l = vl + 1;
    }
    {
        int vl = -1, vr = n + 1;
        while (vl + 1 < vr) {
            int m = (vl + vr) / 2;
            if (check(a, m) == 1) {
                vr = m;
            } else {
                vl = m;
            }
        }
        r = vr - 1;
    }
    //cout << l << " " << r << endl;
    //for (int i = 0; i <= n; i++) {
    //    cout << check(a, i) << " ";
    //} cout << endl;
    if (l <= r) {
        for (int i = l; i <= r; i++) {
            if (i % 2 == sum % 2) {
                cout << i << " ";
            }
        }
    } else {
        cout << -1;
    }
}