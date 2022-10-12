const int MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

const int N = 100'000;

int n;
int a[N], b[N], c[N], d[N];

int solve(set<int> items)
{
    if (items.size() <= 1)
        return 1;

    {
        vector<int> x, y;
        for (auto i : items)
        {
            x.pb(a[i]), x.pb(c[i]);
            y.pb(b[i]), y.pb(d[i]);
        }
        uniq(x);
        uniq(y);

        map<int, int> xc, yc;
        for (int i = 0; i < x.size(); i++)
            xc[x[i]] = i;
        for (int i = 0; i < y.size(); i++)
            yc[y[i]] = i;

        for (auto i : items)
        {
            a[i] = xc[a[i]];
            b[i] = yc[b[i]];
            c[i] = xc[c[i]];
            d[i] = yc[d[i]];
        }
    }

    int mxsz = items.size() * 2;

    struct SegTree{
        vector<pair<int, int> > tree_lines;
        vector<int> pushes;
        vector<int> tree_items;
        SegTree(int sz)
        {
            tree_lines.resize(4 * sz);
            pushes.resize(4 * sz);
            tree_items.resize(sz);
            build(0, sz, 0);
        }

        void build(int L, int R, int V)
        {
            tree_lines[V].second = L;
            if (L + 1 == R)
            {
                return;
            }
            int M = (L + R) / 2;
            build(L, M, 2 * V + 1);
            build(M, R, 2 * V + 2);
        }

        void put_item(int pos, int dir)
        {
            while (pos < tree_items.size())
            {
                tree_items[pos] += dir;
                pos |= (pos + 1);
            }
        }

        int get_items(int pos)
        {
            int res = 0;
            while (pos >= 0)
            {
                res += tree_items[pos];
                pos &= (pos + 1);
                pos--;
            }
            return res;
        }

        void push(int V)
        {
            pushes[2 * V + 1] += pushes[V];
            tree_lines[2 * V + 1].first += pushes[V];
            pushes[2 * V + 2] += pushes[V];
            tree_lines[2 * V + 2].first += pushes[V];
            pushes[V] = 0;
        }

        void add(int l, int r, int x, int L, int R, int V)
        {
            if (r <= L || R <= l)
                return;
            if (l <= L && R <= r)
            {
                tree_lines[V].first += x;
                pushes[V] += x;
                return;
            }
            int M = (L + R) / 2;
            push(V);
            add(l, r, x, L, M, 2 * V + 1);
            add(l, r, x, M, R, 2 * V + 2);
            tree_lines[V] = min(tree_lines[2 * V + 1], tree_lines[2 * V + 2]);
        }

        pair<int, int> get(int l, int r, int L, int R, int V)
        {
            if (r <= L || R <= l)
                return {INF, INF};
            if (l <= L && R <= r)
                return tree_lines[V];
            int M = (L + R) / 2;
            push(V);
            return min(get(l, r, L, M, 2 * V + 1), get(l, r, M, R, 2 * V + 2));
        }

        void put(int l, int r, int dir)
        {
            put_item(l, dir);
            add(l + 1, r, dir, 0, tree_items.size(), 0);
        }

        pair<int, int> check(int l, int r)
        {
            pair<int, int> tmp = get(l + 1, r, 0, tree_items.size(), 0);
            if (tmp.first == 0)
            {
                return {tmp.second, get_items(tmp.second - 1)};
            }
            return {-1, -1};
        }
    };

    SegTree overx(mxsz), overy(mxsz);
    int A = 0, B = 0, C = mxsz, D = mxsz;

    for (auto e : items)
    {
        //cout << "item = " << a[e] << " " << b[e] << " " << c[e] << " " << d[e] << "\n";
        overx.put(a[e], c[e], 1);
        overy.put(b[e], d[e], 1);
    }

    set<pair<int, int> > by_x, by_y;
    for (auto e : items)
    {
        by_x.insert({a[e], e});
        by_y.insert({b[e], e});
    }

    while (items.size() > 1)
    {
        //cout << "AREA " << A << " " << B << " " << C << " " << D << "\n";
        pair<int, int> xx = overx.check(A, C);
        //cout << "FOUND " << xx.fi << " " << xx.se << "\n";
        //cout << "items.size() = " << items.size() << "\n";
        if (xx.first != -1)
        {
            int cnt = xx.second;
            if (2 * cnt < items.size())
            {
                set<int> small;
                for (int i = 0; i < cnt; i++)
                {
                    int id = (*by_x.begin()).second;
                    by_x.erase(by_x.begin());
                    by_y.erase({b[id], id});
                    items.erase(id);
                    overx.put(a[id], c[id], -1);
                    overy.put(b[id], d[id], -1);
                    small.insert(id);
                }

                if (!solve(small))
                    return 0;

                A = xx.first;
            }
            else
            {
                set<int> small;
                int cursz = items.size();
                for (int i = 0; i < cursz - cnt; i++)
                {
                    int id = (*by_x.rbegin()).second;
                    by_x.erase(*(by_x.rbegin()));
                    by_y.erase({b[id], id});
                    items.erase(id);
                    overx.put(a[id], c[id], -1);
                    overy.put(b[id], d[id], -1);
                    small.insert(id);
                }

                if (!solve(small))
                    return 0;

                C = xx.first;
            }
            continue;
        }
        pair<int, int> yy = overy.check(B, D);
        if (yy.first != -1)
        {
            int cnt = yy.second;
            if (2 * cnt < items.size())
            {
                set<int> small;
                for (int i = 0; i < cnt; i++)
                {
                    int id = (*by_y.begin()).second;
                    by_y.erase(by_y.begin());
                    by_x.erase({a[id], id});
                    items.erase(id);
                    overx.put(a[id], c[id], -1);
                    overy.put(b[id], d[id], -1);
                    small.insert(id);
                }

                if (!solve(small))
                    return 0;

                B = yy.first;
            }
            else
            {
                set<int> small;
                int cursz = items.size();
                for (int i = 0; i < cursz - cnt; i++)
                {
                    int id = (*by_y.rbegin()).second;
                    by_y.erase(*(by_y.rbegin()));
                    by_x.erase({a[id], id});
                    items.erase(id);
                    overx.put(a[id], c[id], -1);
                    overy.put(b[id], d[id], -1);
                    small.insert(id);
                }

                if (!solve(small))
                    return 0;

                D = yy.first;
            }
            continue;
        }
        return 0;
    }
    return 1;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    set<int> items;
    for (int i = 0; i < n; i++) items.insert(i);

    cout << YES[solve(items)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}