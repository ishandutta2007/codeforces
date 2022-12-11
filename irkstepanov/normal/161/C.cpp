#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int ans = 0;
int iter = 30;
int mid;

bool inseg(int val, pii p) {
    return val >= p.first && val <= p.second;
}

void norm(pii& p) {
    if (p.first > mid) {
        p.first -= mid;
        p.second -= mid;
    }
}

void fix(vector<pii>& v) {
    for (int i = 1; i < sz(v); ++i) {
        bool del = false;
        for (int j = 0; j < i; ++j) {
            if (v[i].first >= v[j].first && v[i].second <= v[j].second) {
                del = true;
                break;
            }
        }
        if (del) {
            swap(v[i], v.back());
            v.pop_back();
            --i;
             continue;
        }
        int f = -1;
        for (int j = 0; j < i; ++j) {
            if (v[j].first >= v[i].first && v[j].second <= v[i].second) {
                f = j;
                break;
            }
        }
        if (f != -1) {
            swap(v[i], v[f]);
            --i;
        }
    }
}

bool valid(pii p) {
    return p.first <= p.second;
}

void solve(vector<pii> a, vector<pii> b) {
    assert(sz(a) <= 2 && sz(b) <= 2);
    if (iter == 1) {
        ans = max(ans, 1);
        return;
    }
    vector<pii> nxa, nxb;
    mid = (1 << (iter - 1));
    for (pii x : a) {
        for (pii y : b) {
            if (!inseg(mid, x) && !inseg(mid, y)) {
                pii p = x;
                norm(p);
                nxa.pb(p);
                p = y;
                norm(p);
                nxb.pb(p);
            } else if (inseg(mid, x) && !inseg(mid, y)) {
                pii p = x;
                p.second = mid - 1;
                if (valid(p)) nxa.pb(p);
                p = x;
                p.first = mid + 1;
                norm(p);
                if (valid(p)) nxa.pb(p);
                p = y;
                norm(p);
                if (valid(p)) nxb.pb(p);
            } else if (!inseg(mid, x) && inseg(mid, y)) {
                pii p = y;
                p.second = mid - 1;
                if (valid(p)) nxb.pb(p);
                p = y;
                p.first = mid + 1;
                norm(p);
                if (valid(p)) nxb.pb(p);
                p = x;
                norm(p);
                if (valid(p)) nxa.pb(p);
            } else {
                int l = max(x.first, y.first);
                int r = min(x.second, y.second);
                ans = max(ans, r - l + 1);
                pii p = x;
                p.second = mid - 1;
                if (valid(p)) nxa.pb(p);
                p = x;
                p.first = mid + 1;
                norm(p);
                if (valid(p)) nxa.pb(p);
                p = y;
                p.second = mid - 1;
                if (valid(p)) nxb.pb(p);
                p = y;
                p.first = mid + 1;
                norm(p);
                if (valid(p)) nxb.pb(p);
            }
        }
    }
    fix(nxa);
    fix(nxb);
    --iter;
    if (nxa.empty() || nxb.empty()) {
        return;
    }
    solve(nxa, nxb);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<pii> a, b;
    int l, r;
    cin >> l >> r;
    a.pb({l, r});
    cin >> l >> r;
    b.pb({l, r});

    solve(a, b);

    cout << ans << "\n";

}