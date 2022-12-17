#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;
int p[N];

int base = 41;

int bp(int x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int hesh(int x) {
    return bp(base, x);
}


int pos_f(vector <pair<int, int> > &v, int x) {
    int l = 0, r = v.size() + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2 - 1;
        if (v[mid].fi < x)
            l = mid + 1;
        else
            r = mid + 1;
    }
    return l;
}

int pos_l(vector <pair<int, int> > &v, int x) {
    int l = -1, r = v.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (v[mid].fi < x)
            l = mid;
        else
            r = mid;
    }
    return l;
}

bool pruf(vector <int> sa, vector <int> se, vector <int> ta, vector <int> te) {
    vector <pair<int, int> > tesort, tasort, sasort, sesort;
    int n = sa.size();
    int i, j, k;
    for (i = 0; i < n; ++i) {
        sasort.push_back({sa[i], i + 1});
        sesort.push_back({se[i], i + 1});
        tasort.push_back({ta[i], i + 1});
        tesort.push_back({te[i], i + 1});
    }
    sort(tesort.begin(), tesort.end());
    sort(tasort.begin(), tasort.end());
    sort(sasort.begin(), sasort.end());
    sort(sesort.begin(), sesort.end());
    vector <int> suf(n + 1), pref(n + 1);
    suf[n] = 0;
    pref[0] = 0;
    j = n - 1;
    for (i = n - 1; i >= 0; --i) {
        suf[i] = (suf[i + 1] + hesh(tasort[i].se)) % mod;
    }
    j = 0;
    for (i = 1; i <= n; ++i) {
        pref[i] = (pref[i - 1] + hesh(tesort[i - 1].se)) % mod;
    }
    map <int, int> pose, posa;
    for (i = 0; i < n; ++i) {
        posa[tasort[i].se] = i;
        pose[tesort[i].se] = i;
    }
    vector <int> hs1(n + 1), hs2(n + 1);
    int hh = 0;
    j = n - 1;
    for (i = n - 1; i >= 0; --i) {
        while (sasort[j].fi > sesort[i].fi) {
            hh = (hh + hesh(sasort[j].se)) % mod;
            --j;
        }
        hs1[sesort[i].se] = (hs1[sesort[i].se] + hh) % mod;
    }
    hh = 0;
    j = 0;
    for (i = 0; i < n; ++i) {
        while (sesort[j].fi < sasort[i].fi) {
            hh = (hh + hesh(sesort[j].se)) % mod;
            ++j;
        }
        hs1[sasort[i].se] = (hs1[sasort[i].se] + hh) % mod;
    }
    for (i = 1; i <= n; ++i) {
        hs2[i] = (suf[pos_f(tasort, te[i - 1] + 1)] + pref[pos_l(tesort, ta[i - 1]) + 1]) % mod;
        if (hs1[i] != hs2[i])
            return false;
    }
    return true;
}


void solve() {
    int i, j, k, n, m, q;
    cin >> n;
    vector <int> sa(n), se(n), ta(n), te(n);
    for (i = 0; i < n; ++i)
        cin >> sa[i] >> se[i] >> ta[i] >> te[i];
    if (pruf(sa, se, ta, te) && pruf(ta, te, sa, se))
        cout << "Yes";
    else
        cout << "No";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);

    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}