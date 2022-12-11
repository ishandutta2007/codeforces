#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > t;
int n;

ll get(int v, int val)
{
    int pos = lower_bound(all(t[v]), val) - t[v].begin();
    --pos;
    /*cout << "!" << pos << " " << val << "\n";
    for (int x : t[v]) {
        cout << x << " ";
    }
    cout << "\n";*/
    return pos + 1;
}

ll solve(int l, int r)
{
    ll ans = 0;
    int x = l;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans += get(l, x);
        }
        if (!(r & 1)) {
            ans += get(r, x);
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int k;
    cin >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, vector<int> > mapa;
    vector<int> pr(n);
    for (int i = 0; i < n; ++i) {
        if (!mapa.count(a[i])) {
            pr[i] = -1;
            mapa[a[i]].pb(i);
        } else {
            vector<int>& v = mapa[a[i]];
            if (sz(v) - k >= 0) {
                pr[i] = v[sz(v) - k];
            } else {
                pr[i] = -1;
            }
            mapa[a[i]].pb(i);
        }
    }

    t.resize(2 * n);
    for (int i = 0; i < n; ++i) {
        t[i + n] = {pr[i]};
    }
    for (int i = n - 1; i; --i) {
        t[i].resize(sz(t[i * 2]) + sz(t[i * 2 + 1]));
        merge(t[i * 2].begin(), t[i * 2].end(), t[i * 2 + 1].begin(), t[i * 2 + 1].end(), t[i].begin());
    }

    ll last = 0;
    int q;
    cin >> q;

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l = (l + last) % n, r = (r + last) % n;
        if (l > r) {
            swap(l, r);
        }
        //cout << l + 1 << " " << r + 1 << endl;
        last = solve(l, r);
        cout << last << '\n';
    }

}