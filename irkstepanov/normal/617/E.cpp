#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

struct query
{
    int l, r;
    int id;
    bool operator<(const query& other) const
    {
        return r < other.r;
    }
};

const int blockSize = 317;

int k;
int cnt[1 << 20];
ll ans;

void add(int x)
{
    ans += cnt[x ^ k];
    ++cnt[x];
}

void del(int x)
{
    --cnt[x];
    ans -= cnt[x ^ k];
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("division.out");

    int n, q;
    cin >> n >> q >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }

    vector<vector<query> > v((n + blockSize - 1) / blockSize);
    for (int i = 0; i < q; ++i) {
        query t;
        cin >> t.l >> t.r;
        --t.l;
        t.id = i;
        v[t.l / blockSize].pb(t);
    }

    for (int i = 0; i < sz(v); ++i) {
        sort(all(v[i]));
    }

    vector<ll> res(q);

    for (int i = 0; i < sz(v); ++i) {
        ans = 0;
        if (v[i].empty()) {
            continue;
        }
        int l = i * blockSize, r;
        for (r = l; r <= v[i][0].r; ++r) {
            add(pref[r]);
        }
        r = v[i][0].r;
        for (; l < v[i][0].l; ++l) {
            del(pref[l]);
        }
        res[v[i][0].id] = ans;
        for (int j = 1; j < sz(v[i]); ++j) {
            if (r < v[i][j].r) {
                for (++r; r <= v[i][j].r; ++r) {
                    add(pref[r]);
                    //cout << "!" << pref[r] << "\n";
                }
                r = v[i][j].r;
            }
            if (l < v[i][j].l) {
                for (; l < v[i][j].l; ++l) {
                    del(pref[l]);
                }
            }
            if (l > v[i][j].l) {
                for (--l; l >= v[i][j].l; --l) {
                    add(pref[l]);
                    //cout << "!!" << pref[l] << "\n";
                }
                l = v[i][j].l;
            }
            res[v[i][j].id] = ans;
        }
        for (; l <= r; ++l) {
            del(pref[l]);
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << res[i] << "\n";
    }

}