#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int m;
vector<ll> d;

void add(ll val) {
    if (d.back() >= val) {
        d.pb(val);
        return;
    }
    int pos = 0;
    while (d[pos] >= val) {
        ++pos;
    }
    d.insert(d.begin() + pos, val);
}

int flag;

bool valid(ll added = 0) {
    int n = m + 1;
    for (int i = 0; i < n; ++i) {
        if (d[i] > n - 1) {
            flag = -1;
            return false;
        }
    }
    int lf = 1;
    int rg = 0;
    while (rg + 1 < n && d[rg + 1] >= 1) {
        ++rg;
    }
    vector<ll> pref(n);
    pref[0] = d[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + d[i];
    }

    vector<ll> suff(n + 1);
    suff[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + d[i];
    }
    for (int k = 1; k < n; ++k) {
        ll val = ll(k) * (k - 1);
        if (lf <= rg) {
            val += ll(rg - lf + 1) * k;
            val += suff[rg + 1];
        } else {
            val += suff[k];
        }
        if (pref[k - 1] > val) {
            if (d[k - 1] > added) {
                flag = 1;
            } else if (d[k - 1] < added) {
                flag = -1;
            } else if (d[k - 1] == added) {
                if (d[k - 1] == d[k]) {
                    flag = 1;
                } else {
                    flag = -1;
                }
            }
            return false;
        }
        ++lf;
        while (rg >= 0 && d[rg] == k) {
            --rg;
        }
    }
    flag = 1;
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;

    vector<ll> a(m);
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    reverse(all(a));

    int lf = 0, rg = m / 2 + 1;

    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        int deg = md * 2;
        if (sum & 1) {
            ++deg;
        }
        d = a;
        add(deg);
        valid(deg);
        if (flag == 1) {
            lf = md;
        } else {
            rg = md;
        }
    }

    {
        int deg = lf * 2;
        if (sum & 1) {
            ++deg;
        }
        d = a;
        add(deg);
        if (!valid()) {
            cout << "-1\n";
            return 0;
        }
    }

    int ub = lf;
    rg = lf;
    lf = -1;

    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        int deg = md * 2;
        if (sum & 1) {
            ++deg;
        }
        d = a;
        add(deg);
        if (valid()) {
            rg = md;
        } else {
            lf = md;
        }
    }

    for (int j = rg; j <= ub; ++j) {
        int deg = j * 2;
        if (sum & 1) {
            ++deg;
        }
        cout << deg << " ";
    }
    cout << "\n";

}