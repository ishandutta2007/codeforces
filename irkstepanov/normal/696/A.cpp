#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

vector<int> conv(ll a)
{
    vector<int> ans;
    while (a) {
        ans.pb(a % 2);
        a >>= 1;
    }
    reverse(all(ans));
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<ll, ll> m;
    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll u, v, w;
            cin >> u >> v >> w;
            if (u > v) {
                swap(u, v);
            }
            vector<int> a = conv(u);
            vector<int> b = conv(v);
            int last = 0;
            for (int i = 1; i < sz(a); ++i) {
                if (a[i] != b[i]) {
                    break;
                } else {
                    last = i;
                }
            }
            for (int i = sz(a) - 1; i > last; --i) {
                m[u] += w;
                u >>= 1;
            }
            for (int i = last + 1; i < sz(b); ++i) {
                u <<= 1;
                u += b[i];
                m[u] += w;
            }
        } else {
            ll u, v;
            cin >> u >> v;
            if (u > v) {
                swap(u, v);
            }
            vector<int> a = conv(u);
            vector<int> b = conv(v);
            ll ans = 0;
            int last = 0;
            for (int i = 1; i < sz(a); ++i) {
                if (a[i] != b[i]) {
                    break;
                } else {
                    last = i;
                }
            }
            for (int i = sz(a) - 1; i > last; --i) {
                if (m.count(u)) {
                    ans += m[u];
                }
                u >>= 1;
            }
            for (int i = last + 1; i < sz(b); ++i) {
                u <<= 1;
                u += b[i];
                if (m.count(u)) {
                    ans += m[u];
                }
            }
            cout << ans << "\n";
        }
    }

}