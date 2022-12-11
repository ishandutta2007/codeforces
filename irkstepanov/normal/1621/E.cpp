#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct node {
    ll sum;
    ll suff;
    node() : sum(0), suff(0) {}
};

vector<node> t;

void merge(int v) {
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    t[v].suff = min(t[v * 2 + 1].suff, t[v * 2 + 1].sum + t[v * 2].suff);
}

void build(int v, int tl, int tr, vector<int>& a) {
    if (tl == tr) {
        t[v].sum = a[tl];
        t[v].suff = (t[v].sum < 0 ? t[v].sum : 0);
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    merge(v);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v].sum += val;
        t[v].suff = (t[v].sum < 0 ? t[v].sum : 0);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    merge(v);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        map<int, int> mapa;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++mapa[a[i] * 2];
        }
        vector<vector<int> > b(m);
        vector<ll> sum(m);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            b[i].resize(k);
            sum[i] = 0;
            for (int j = 0; j < k; ++j) {
                cin >> b[i][j];
                sum[i] += b[i][j];
            }
            if (sum[i] % k == 0) {
                --mapa[sum[i] / k * 2];
            } else {
                --mapa[sum[i] / k * 2 + 1];
            }
            for (int j = 0; j < k; ++j) {
                ll s = sum[i] - b[i][j];
                if (s % (k - 1) == 0) {
                    mapa[s / (k - 1) * 2];
                } else {
                    mapa[s / (k - 1) * 2 + 1];
                }
            }
        }
        int N = sz(mapa);
        vector<int> vals, vct;
        for (auto it : mapa) {
            vals.pb(it.first);
            vct.pb(it.second);
        }
        t = vector<node>(4 * N);
        build(1, 0, N - 1, vct);
        for (int i = 0; i < m; ++i) {
            int k = sz(b[i]);
            int old;
            if (sum[i] % k == 0) {
                old = sum[i] / k * 2;
            } else {
                old = sum[i] / k * 2 + 1;
            }
            update(1, 0, N - 1, lower_bound(all(vals), old) - vals.begin(), 1);

            for (int j = 0; j < k; ++j) {
                int nx;
                ll s = sum[i] - b[i][j];
                if (s % (k - 1) == 0) {
                    nx = s / (k - 1) * 2;
                } else {
                    nx = s / (k - 1) * 2 + 1;
                }
                update(1, 0, N - 1, lower_bound(all(vals), nx) - vals.begin(), -1);
                cout << (t[1].suff < 0 ? 0 : 1);
                update(1, 0, N - 1, lower_bound(all(vals), nx) - vals.begin(), 1);
            }

            update(1, 0, N - 1, lower_bound(all(vals), old) - vals.begin(), -1);
        }
        cout << "\n";
    }

}