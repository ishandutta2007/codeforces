#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void ins(vector<pii>& v, int pos, pii p) {
    vector<pii> ans;
    for (int i = 0; i < pos; ++i) {
        ans.pb(v[i]);
    }
    ans.pb(p);
    for (int i = pos; i < sz(v); ++i) {
        ans.pb(v[i]);
    }
    v.swap(ans);
}

void er(vector<pii>& v, int x) {
    vector<pii> ans;
    for (int i = 0; i < sz(v); ++i) {
        if (v[i].first == x) {
            continue;
        }
        ans.pb(v[i]);
    }
    v.swap(ans);
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, b, f;
    cin >> l >> b >> f;

    int q;
    cin >> q;

    vector<pii> occ;
    vector<int> ans(q, -1);
    vector<bool> type(q, false);

    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            type[i] = true;
            int len;
            cin >> len;
            int pos = 0;
            if (occ.empty() || 0 + len + f <= occ[0].first) {
                if (len <= l) {
                    ans[i] = 0;
                    ins(occ, 0, {0, len});
                } else {
                    ans[i] = -1;
                }
            } else {
                for (int j = 0; j < sz(occ); ++j) {
                    bool ok = false;
                    if (j == sz(occ) - 1) {
                        if (occ[j].second + b + len <= l) {
                            ok = true;
                        }
                    } else {
                        if (occ[j].second + b + len + f <= occ[j + 1].first) {
                            ok = true;
                        }
                    }
                    if (ok) {
                        ans[i] = occ[j].second + b;
                        ins(occ, j + 1, {ans[i], ans[i] + len});
                        break;
                    }
                }
            }
        } else {
            int id;
            cin >> id;
            --id;
            er(occ, ans[id]);
        }
    }

    for (int i = 0; i < q; ++i) {
        if (type[i]) {
            cout << ans[i] << "\n";
        }
    }
    

}