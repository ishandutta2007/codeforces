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

const int inf = 1e9;

struct query
{
    char type;
    int x, y;
};

int q;
vector<int> t;
vector<set<int> > s;

void update(int v, int tl, int tr, int pos)
{
    if (tl == tr) {
        if (s[pos].empty()) {
            t[v] = -inf;
        } else {
            auto it = s[pos].end();
            --it;
            t[v] = *it;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r, int val)
{
    if (t[v] <= val) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        int ans = get(v * 2, tl, tm, l, min(r, tm), val);
        if (ans != -1) {
            return ans;
        }
    }
    if (r > tm) {
        return get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
    return -1;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    scanf("%d", &q);

    char type[10];
    vector<query> queries(q);
    vector<int> sorted_x(q), sorted_y(q);
    for (int i = 0; i < q; ++i) {
        scanf("%s", type);
        queries[i].type = type[0];
        scanf("%d%d", &queries[i].x, &queries[i].y);
        sorted_x[i] = queries[i].x;
        sorted_y[i] = queries[i].y;
    }
    sort(all(sorted_x));
    sort(all(sorted_y));
    sorted_x.resize(unique(all(sorted_x)) - sorted_x.begin());
    sorted_y.resize(unique(all(sorted_y)) - sorted_y.begin());
    for (int i = 0; i < q; ++i) {
        queries[i].x = lower_bound(all(sorted_x), queries[i].x) - sorted_x.begin();
        queries[i].y = lower_bound(all(sorted_y), queries[i].y) - sorted_y.begin();
    }

    t.resize(4 * q);
    s.resize(q);

    for (int i = 0; i < q; ++i) {
        if (queries[i].type == 'a') {
            s[queries[i].x].insert(queries[i].y);
            update(1, 0, q - 1, queries[i].x);
        } else if (queries[i].type == 'r') {
            s[queries[i].x].erase(queries[i].y);
            update(1, 0, q - 1, queries[i].x);
        } else {
            if (queries[i].x == sz(sorted_x) - 1) {
                printf("-1\n");
                continue;
            }
            int pos = get(1, 0, q - 1, queries[i].x + 1, q - 1, queries[i].y);
            if (pos == -1) {
                printf("-1\n");
                continue;
            }
            auto it = s[pos].upper_bound(queries[i].y);
            printf("%d %d\n", sorted_x[pos], sorted_y[*it]);
        }
    }

}