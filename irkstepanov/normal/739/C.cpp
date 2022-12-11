#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
typedef long double ld;

struct node1
{
    ll promise;
    ll val;
    node1() : promise(0) {}
};

vector<node1> t1;
int n;

void build1(int v, int tl, int tr, vector<ll>& a)
{
    if (tl == tr) {
        t1[v].val = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build1(v * 2, tl, tm, a);
    build1(v * 2 + 1, tm + 1, tr, a);
}

void push1(int v)
{
    if (t1[v].promise != 0) {
        t1[v * 2].val += t1[v].promise;
        t1[v * 2].promise += t1[v].promise;
        t1[v * 2 + 1].val += t1[v].promise;
        t1[v * 2 + 1].promise += t1[v].promise;
        t1[v].promise = 0;
    }
}

void update1(int v, int tl, int tr, int l, int r, ll val)
{
    if (tl == l && tr == r) {
        t1[v].val += val;
        t1[v].promise += val;
        return;
    }
    push1(v);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update1(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update1(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}

ll get1(int v, int tl, int tr, int pos)
{
    if (tl == tr) {
        return t1[v].val;
    }
    push1(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return get1(v * 2, tl, tm, pos);
    } else {
        return get1(v * 2 + 1, tm + 1, tr, pos);
    }
}

struct node2
{
    int maxrg, minlf;
    int maxd;
    int promiself, promiserg;
    node2() : promiself(-1), promiserg(-1) {}
};

vector<node2> t2;

void build2(int v, int tl, int tr, vector<int>& lf, vector<int>& rg)
{
    if (tl == tr) {
        t2[v].maxrg = rg[tl];
        t2[v].minlf = lf[tl];
        t2[v].maxd = t2[v].maxrg - t2[v].minlf + 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    build2(v * 2, tl, tm, lf, rg);
    build2(v * 2 + 1, tm + 1, tr, lf, rg);
    t2[v].maxrg = max(t2[v * 2].maxrg, t2[v * 2 + 1].maxrg);
    t2[v].minlf = min(t2[v * 2].minlf, t2[v * 2 + 1].minlf);
    t2[v].maxd = max(t2[v * 2].maxd, t2[v * 2 + 1].maxd);
}

void push2(int v)
{
    if (t2[v].promiself != -1) {
        t2[v * 2].minlf = t2[v].promiself;
        t2[v * 2].promiself = t2[v].promiself;
        t2[v * 2].maxd = t2[v * 2].maxrg - t2[v * 2].minlf + 1;
        t2[v * 2 + 1].minlf = t2[v].promiself;
        t2[v * 2 + 1].promiself = t2[v].promiself;
        t2[v * 2 + 1].maxd = t2[v * 2 + 1].maxrg - t2[v * 2 + 1].minlf + 1;
        t2[v].promiself = -1;
    }
    if (t2[v].promiserg != -1) {
        t2[v * 2].maxrg = t2[v].promiserg;
        t2[v * 2].promiserg = t2[v].promiserg;
        t2[v * 2].maxd = t2[v * 2].maxrg - t2[v * 2].minlf + 1;
        t2[v * 2 + 1].maxrg = t2[v].promiserg;
        t2[v * 2 + 1].promiserg = t2[v].promiserg;
        t2[v * 2 + 1].maxd = t2[v * 2 + 1].maxrg - t2[v * 2 + 1].minlf + 1;
        t2[v].promiserg = -1;
    }
}

void assign2rg(int v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        t2[v].maxrg = val;
        t2[v].promiserg = val;
        t2[v].maxd = t2[v].maxrg - t2[v].minlf + 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    push2(v);
    if (l <= tm) {
        assign2rg(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        assign2rg(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t2[v].maxrg = max(t2[v * 2].maxrg, t2[v * 2 + 1].maxrg);
    t2[v].minlf = min(t2[v * 2].minlf, t2[v * 2 + 1].minlf);
    t2[v].maxd = max(t2[v * 2].maxd, t2[v * 2 + 1].maxd);
}

void assign2lf(int v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        t2[v].minlf = val;
        t2[v].promiself = val;
        t2[v].maxd = t2[v].maxrg - t2[v].minlf + 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    push2(v);
    if (l <= tm) {
        assign2lf(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        assign2lf(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t2[v].maxrg = max(t2[v * 2].maxrg, t2[v * 2 + 1].maxrg);
    t2[v].minlf = min(t2[v * 2].minlf, t2[v * 2 + 1].minlf);
    t2[v].maxd = max(t2[v * 2].maxd, t2[v * 2 + 1].maxd);
}

int get2lf(int v, int tl, int tr, int pos)
{
    if (tl == tr) {
        return t2[v].minlf;
    }
    push2(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return get2lf(v * 2, tl, tm, pos);
    } else {
        return get2lf(v * 2 + 1, tm + 1, tr, pos);
    }
}

int get2rg(int v, int tl, int tr, int pos)
{
    if (tl == tr) {
        return t2[v].maxrg;
    }
    push2(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return get2rg(v * 2, tl, tm, pos);
    } else {
        return get2rg(v * 2 + 1, tm + 1, tr, pos);
    }
}

pii getpos(int x, set<pii>& s)
{
    set<pii>::iterator it = s.lower_bound({x + 1, x + 1});
    --it;
    pii ans = *it;
    s.erase(it);
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("wa");

    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    t1.resize(4 * n);
    build1(1, 0, n - 1, a);

    t2.resize(4 * n);
    vector<int> lf(n), rg(n);
    lf[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            lf[i] = lf[i - 1];
        } else {
            lf[i] = i;
        }
    }
    rg[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) {
            rg[i] = rg[i + 1];
        } else {
            rg[i] = i;
        }
    }
    build2(1, 0, n - 1, lf, rg);

    set<pii> setlf, setrg;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        if (i && lf[i] != lf[i - 1]) {
            setlf.insert({prev, i - 1});
            prev = i;
        }
    }
    setlf.insert({prev, n - 1});
    prev = 0;
    for (int i = 0; i < n; ++i) {
        if (i && rg[i] != rg[i - 1]) {
            setrg.insert({prev, i - 1});
            prev = i;
        }
    }
    setrg.insert({prev, n - 1});

    int q;
    scanf("%d", &q);

    while (q--) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        --l, --r;
        update1(1, 0, n - 1, l, r, d);
        if (l > 0) {
            ll x = get1(1, 0, n - 1, l - 1);
            ll y = get1(1, 0, n - 1, l);
            if (x > y - d && x <= y) {
                pii p = getpos(l - 1, setrg);
                assign2rg(1, 0, n - 1, p.first, l - 1, l - 1);
                setrg.insert({p.first, l - 1});
                setrg.insert({l, p.second});
            }
            if (y - d <= x && y > x) {
                pii p = getpos(l, setlf);
                pii q = getpos(l - 1, setlf);
                assign2lf(1, 0, n - 1, q.first, p.second, get2lf(1, 0, n - 1, l - 1));
                setlf.insert({q.first, p.second});
            }
        }
        if (r + 1 < n) {
            ll x = get1(1, 0, n - 1, r + 1);
            ll y = get1(1, 0, n - 1, r);
            if (x > y - d && x <= y) {
                pii p = getpos(r + 1, setlf);
                assign2lf(1, 0, n - 1, r + 1, p.second, r + 1);
                setlf.insert({r + 1, p.second});
                setlf.insert({p.first, r});
            }
            if (y - d <= x && y > x) {
                pii p = getpos(r, setrg);
                pii q = getpos(r + 1, setrg);
                assign2rg(1, 0, n - 1, p.first, q.second, get2rg(1, 0, n - 1, r + 1));
                setrg.insert({p.first, q.second});
            }
        }
        printf("%d\n", t2[1].maxd);
    }

}