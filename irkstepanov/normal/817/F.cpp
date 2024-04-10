#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct node
{
    int sum;
    int assign;
    int rexor;
    node() : sum(0), assign(-1), rexor(0) {}
};

vector<node> t;

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    if (t[v].assign != -1) {
        t[v * 2].assign = t[v * 2 + 1].assign = t[v].assign;
        t[v * 2].rexor = t[v * 2 + 1].rexor = 0;
        t[v * 2].sum = t[v].assign * (tm - tl + 1);
        t[v * 2 + 1].sum = t[v].assign * (tr - tm);
        t[v].assign = -1;
    }
    if (t[v].rexor == 1) {
        t[v * 2].rexor ^= 1;
        t[v * 2 + 1].rexor ^= 1;
        t[v].rexor = 0;
        t[v * 2].sum = (tm + 1 - tl) - t[v * 2].sum;
        t[v * 2 + 1].sum = (tr - tm) - t[v * 2 + 1].sum;
    }
}

void merge(int v)
{
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}

void assign(int v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        t[v].sum = val * (tr - tl + 1);
        t[v].assign = val;
        t[v].rexor = 0;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (l <= tm) {
        assign(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        assign(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    merge(v);
}

void rexor(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        t[v].sum = (tr - tl + 1) - t[v].sum;
        t[v].rexor ^= 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (l <= tm) {
        rexor(v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        rexor(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    merge(v);
}

int get(int v, int tl, int tr)
{
    if (tl == tr) {
        assert(t[v].sum == 0);
        return tl;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (t[v * 2].sum < tm - tl + 1) {
        return get(v * 2, tl, tm);
    } else {
        return get(v * 2 + 1, tm + 1, tr);
    }
}

struct query
{
    int type;
    ll l, r;
};

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    vector<query> queries(q);
    vector<ll> sorted;
    sorted.pb(1);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type >> queries[i].l >> queries[i].r;
        sorted.pb(queries[i].l);
        sorted.pb(queries[i].r);
        if (queries[i].l - 1 >= 1) {
            sorted.pb(queries[i].l - 1);
        }
        sorted.pb(queries[i].r + 1);
    }
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());
    int N = sz(sorted);

    t.resize(4 * N);

    for (int i = 0; i < q; ++i) {
        int l = lower_bound(all(sorted), queries[i].l) - sorted.begin();
        int r = lower_bound(all(sorted), queries[i].r) - sorted.begin();
        if (queries[i].type == 1) {
            assign(1, 0, N - 1, l, r, 1);
        } else if (queries[i].type == 2) {
            assign(1, 0, N - 1, l, r, 0);
        } else {
            rexor(1, 0, N - 1, l, r);
        }
        int ans = get(1, 0, N - 1);
        cout << sorted[ans] << "\n";
    }

}