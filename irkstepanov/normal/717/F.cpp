#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int inf = 2e9;

struct node
{
    int promise;
    int minn;
    node() : promise(0), minn(inf) {}
};

vector<vector<node> > t(2);

void push(int id, int v)
{
    int x = t[id][v].promise;
    t[id][v].promise = 0;
    t[id][v * 2].promise += x;
    t[id][v * 2].minn += x;
    t[id][v * 2 + 1].promise += x;
    t[id][v * 2 + 1].minn += x;
}

void init(int id, int v, int tl, int tr, int pos, int val)
{
    if (tl == tr) {
        t[id][v].minn = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        init(id, v * 2, tl, tm, pos, val);
    } else {
        init(id, v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[id][v].minn = min(t[id][v * 2].minn, t[id][v * 2 + 1].minn);
}

int get(int id, int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return t[id][v].minn;
    }
    push(id, v);
    int tm = (tl + tr) >> 1;
    int ans = inf;
    if (l <= tm) {
        ans = min(ans, get(id, v * 2, tl, tm, l, min(r, tm)));
    }
    if (r > tm) {
        ans = min(ans, get(id, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    return ans;
}

void update(int id, int v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        t[id][v].promise += val;
        t[id][v].minn += val;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(id, v);
    if (l <= tm) {
        update(id, v * 2, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update(id, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    t[id][v].minn = min(t[id][v * 2].minn, t[id][v * 2 + 1].minn);
}

int n, cnt_odd, cnt_even;

void add_to_suffix(int pos, int val)
{
    if (pos >= n) {
        return;
    }
    if (pos & 1) {
        update(1, 1, 0, cnt_odd - 1, pos / 2, cnt_odd - 1, val);
    } else {
        update(0, 1, 0, cnt_even - 1, pos / 2, cnt_even - 1, val);
    }
}

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    cnt_odd = n / 2;
    cnt_even = n - cnt_odd;
    t[0] = vector<node>(cnt_even * 4);
    t[1] = vector<node>(cnt_odd * 4);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = a[i] - sum;
        if (i & 1) {
            init(1, 1, 0, cnt_odd - 1, i / 2, sum);
        } else {
            init(0, 1, 0, cnt_even - 1, i / 2, sum);
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l > r) {
                swap(l, r);
            }
            int pref = 0;
            if (l) {
                int x = l - 1;
                if (x & 1) {
                    pref = get(1, 1, 0, cnt_odd - 1, x / 2, x / 2);
                } else {
                    pref = get(0, 1, 0, cnt_even - 1, x / 2, x / 2);
                }
            }
            bool ok = true;
            if (l & 1) {
                int lf = l / 2, rg = (r - 1) / 2;
                int y = get(1, 1, 0, cnt_odd - 1, lf, rg) + pref;
                if (y - 1 < 0) {
                    ok = false;
                }
                lf = (l + 1) / 2, rg = r / 2;
                if (lf <= rg) {
                    int y = get(0, 1, 0, cnt_even - 1, lf, rg) - pref;
                    if (y < 0) {
                        ok = false;
                    }
                }
            } else {
                int lf = l / 2, rg = r / 2;
                int y = get(0, 1, 0, cnt_even - 1, lf, rg) + pref;
                if (y - 1 < 0) {
                    ok = false;
                }
                lf = l / 2, rg = (r - 1) / 2;
                if (lf <= rg) {
                    y = get(1, 1, 0, cnt_odd - 1, lf, rg) - pref;
                    if (y < 0) {
                        ok = false;
                    }
                }
            }
            int len = (r - l + 1);
            if (r & 1) {
                int y = get(1, 1, 0, cnt_odd - 1, r / 2, r / 2);
                if (len & 1) {
                    y += pref;
                } else {
                    y -= pref;
                }
                if (len & 1) {
                    --y;
                }
                if (y != 0) {
                    ok = false;
                }
            } else {
                int y = get(0, 1, 0, cnt_even - 1, r / 2, r / 2);
                if (len & 1) {
                    y += pref;
                } else {
                    y -= pref;
                }
                if (len & 1) {
                    --y;
                }
                if (y != 0) {
                    ok = false;
                }
            }
            if (ok) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            if (l & 1) {
                int lf = l / 2, rg = (r - 1) / 2;
                update(1, 1, 0, cnt_odd - 1, lf, rg, k);
            } else {
                int lf = l / 2, rg = r / 2;
                update(0, 1, 0, cnt_even - 1, lf, rg, k);
            }
            int len = (r - l + 1);
            if (len & 1) {
                add_to_suffix(r + 1, -k);
                add_to_suffix(r + 2, k);
            }
        }
    }

}