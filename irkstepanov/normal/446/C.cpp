#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 9;
const int nmax = 300500;

void mult(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

struct node
{
    ll a, b;
    ll sum;
};

vector<ll> F;
vector<node> t;

ll getSum(ll a, ll b, int n)
{
    if (!n) {
        return 0;
    }
    ll ans = F[n];
    mult(ans, a);
    ll t = F[n + 1] - 1;
    if (t < 0) {
        t += mod;
    }
    mult(t, b);
    add(ans, t);
    return ans;
}

ll findVal(ll a, ll b, int n)
{
    if (n == 1) {
        return a;
    }
    ll ans = F[n - 2];
    mult(ans, a);
    ll t = F[n - 1];
    mult(t, b);
    add(ans, t);
    return ans;
}

void push(int v, int tl, int tr)
{
    if (!t[v].a && !t[v].b) {
        return;
    }
    int tm = (tl + tr) >> 1;
    add(t[v * 2].sum, getSum(t[v].a, t[v].b, tm - tl + 1));
    int passed = tm - tl + 1;
    ll c = findVal(t[v].a, t[v].b, passed + 1);
    ll d = findVal(t[v].a, t[v].b, passed + 2);
    add(t[v * 2 + 1].sum, getSum(c, d, tr - tm));
    add(t[v * 2].a, t[v].a);
    add(t[v * 2].b, t[v].b);
    add(t[v * 2 + 1].a, c);
    add(t[v * 2 + 1].b, d);
    t[v].a = t[v].b = 0;
}

void update(int v, int tl, int tr, int l, int r, ll a, ll b)
{
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        add(t[v].sum, getSum(a, b, tr - tl + 1));
        add(t[v].a, a);
        add(t[v].b, b);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (r <= tm) {
        update(v * 2, tl, tm, l, r, a, b);
    } else if (l > tm) {
        update(v * 2 + 1, tm + 1, tr, l, r, a, b);
    } else {
        update(v * 2, tl, tm, l, tm, a, b);
        int passed = tm - l + 1;
        ll c = findVal(a, b, passed + 1);
        ll d = findVal(a, b, passed + 2);
        update(v * 2 + 1, tm + 1, tr, tm + 1, r, c, d);
    }
    t[v].sum = t[v * 2].sum;
    add(t[v].sum, t[v * 2 + 1].sum);
}

ll get(int v, int tl, int tr, int l, int r)
{
    if (l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return t[v].sum;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    ll ans = get(v * 2, tl, tm, l, min(r, tm));
    add(ans, get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    F.resize(nmax);
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i < nmax; ++i) {
        F[i] = F[i - 1];
        add(F[i], F[i - 2]);
    }

    int n, q;
    scanf("%d%d", &n, &q);

    t.resize(4 * n);

    for (int i = 0; i < n; ++i) {
        ll a;
        scanf("%I64d", &a);
        update(1, 0, n - 1, i, i, a, a);
    }

    while (q--) {
        int type;
        scanf("%d", &type);
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        if (type == 1) {
            update(1, 0, n - 1, l, r, 1, 1);
        } else {
            ll ans = get(1, 0, n - 1, l, r);
            printf("%I64d\n", ans);
        }
    }

}