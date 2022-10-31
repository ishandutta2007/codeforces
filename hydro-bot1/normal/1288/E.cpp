// Hydro submission #62c56381c3a9fda562296b3c@1657103234422
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF = 1e9;
const ll LNF = 1e18;
const int M = 1000000007;

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;

    fenwick(int _n) : n(_n)  {
        fenw.resize(n + 1);
    }

    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x += x & (-x);
        }
    }

    T get(int x) {
        T v{};
        while (x > 0) {
            v += fenw[x];
            x -= x & (-x);
        }
        return v;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
fenwick<ll> fenw(600005);

int n, m;
vl mi, ma, rec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> n >> m;
    mi.resize(n + 1);
    rec.resize(n + 1 + m);
    ma.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        mi[i] = i; rec[i] = n + 1 - i; ma[i] = i;
        fenw.modify(i, 1);
    }
    for (int i = n + 1; i < n + 1 + m; i++) {
        int x;
        cin >> x;
        mi[x] = 1;
        ma[x] = max(ma[x], fenw.get(rec[x], 600001));
        fenw.modify(rec[x], -1LL);
        rec[x] = i;
        fenw.modify(rec[x], 1LL);
    }
    for (int i = 1; i <= n; i++) {
        ma[i] = max(ma[i], fenw.get(rec[i], 600001));
        cout << mi[i] << ' ' << ma[i] << endl;
    }
}