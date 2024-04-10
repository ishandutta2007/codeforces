#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

struct node
{
    int promise;
    int maxx;
};

vector<node> t;

void build(int v, int tl, int tr, vector<int>& a)
{
    if (tl == tr) {
        t[v] = {0, a[tl]};
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].promise = 0;
    t[v].maxx = max(t[v * 2].maxx, t[v * 2 + 1].maxx);
}

void push(int v)
{
    t[v * 2].promise += t[v].promise;
    t[v * 2].maxx += t[v].promise;
    t[v * 2 + 1].promise += t[v].promise;
    t[v * 2 + 1].maxx += t[v].promise;
    t[v].promise = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        t[v].promise += val;
        t[v].maxx += val;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t[v].maxx = max(t[v * 2].maxx, t[v * 2 + 1].maxx);
}

void assign(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr) {
        t[v].maxx = val;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        assign(v * 2, tl, tm, pos, val);
    } else {
        assign(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v].maxx = max(t[v * 2].maxx, t[v * 2 + 1].maxx);
}

int get(int v, int tl, int tr)
{
    if (tl == tr) {
        if (t[v].maxx > 0) {
            return tl;
        } else {
            return -1;
        }
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (t[v * 2 + 1].maxx > 0) {
        return get(v * 2 + 1, tm + 1, tr);
    } else {
        return get(v * 2, tl, tm);
    }
}

struct query
{
    int pos;
    int type;
    int x;
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<query> a(n), v(n);
    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;
        --pos;
        int type;
        cin >> type;
        int x;
        if (type == 1) {
            cin >> x;
        }
        v[i] = {pos, type, x};
        a[pos] = {pos, type, x};
    }

    vector<int> balance(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) {
            balance[i] = balance[i + 1];
        }
        if (a[i].type == 0) {
            --balance[i];
        } else {
            ++balance[i];
        }
    }

    t.resize(4 * n);
    build(1, 0, n - 1, balance);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        int g = get(1, 0, n - 1);
        if (g == -1) {
            ans[i] = -1;
        } else {
            ans[i] = a[g].x;
        }
        if (v[i].type == 0) {
            update(1, 0, n - 1, 0, v[i].pos, 1);
            assign(1, 0, n - 1, v[i].pos, -inf);
        } else {
            update(1, 0, n - 1, 0, v[i].pos, -1);
            assign(1, 0, n - 1, v[i].pos, -inf);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

}