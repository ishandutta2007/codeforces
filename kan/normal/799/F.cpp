#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

#define ends ends_bada

const int maxn = 1000006;
const int treesize = 1 << 19;

struct ttree
{
    int add, cnt;
    ll sum;
};

int l[maxn], r[maxn];
vector<int> begins[maxn], ends[maxn];
multiset<int> banfrom[2];
int n, m;
ttree treeeven[2 * treesize], treeodd[2 * treesize];
ll answer;
set<int> ls;

inline pair<int, ll> sumpairs(const pair<int, ll> &a, const pair<int, ll> &b)
{
    return {a.fi + b.fi, a.se + b.se};
}

inline pair<int, ll> getans(const ttree &elem)
{
    return elem.add == 0 ? make_pair(elem.cnt, elem.sum) : make_pair(0, (ll)0);
}

inline void update(ttree * const tree, int cur)
{
    tie(tree[cur].cnt, tree[cur].sum) = sumpairs(getans(tree[cur * 2]), getans(tree[cur * 2 + 1]));
}

void add(ttree * const tree, int cur, int cl, int cr, int l, int r, int t)
{
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r)
    {
//         cout << "add " << tree << ' ' << cl << ' ' << cr << ' ' << t << endl;
        tree[cur].add += t;
        return;
    }
    int cm = (cl + cr) / 2;
    add(tree, cur * 2, cl, cm, l, r, t);
    add(tree, cur * 2 + 1, cm + 1, cr, l, r, t);
    update(tree, cur);
}

pair<int, ll> get(ttree * const tree, int cur, int cl, int cr, int l, int r)
{
    if (cl > r || cr < l) return {0, 0};
    if (cl >= l && cr <= r)
    {
//         cout << "get " << tree << ' ' << cl << ' ' << cr << ' ' << tree[cur].add << ' ' << tree[cur].cnt << ' ' << tree[cur].sum << endl;
        return getans(tree[cur]);
    }
    if (tree[cur].add != 0) return {0, 0};
    int cm = (cl + cr) / 2;
    return sumpairs(get(tree, cur * 2, cl, cm, l, r), get(tree, cur * 2 + 1, cm + 1, cr, l, r));
}

inline void addeven(int l, int r, int t)
{
    add(treeeven, 1, 0, treesize - 1, (l + 1) / 2, r / 2, t);
}

inline void addodd(int l, int r, int t)
{
    add(treeodd, 1, 0, treesize - 1, l / 2, r / 2 - (1 - r % 2), t); // pb : (r - 1) / 2 when r = 0
}

inline pair<int, ll> geteven(int l, int r)
{
    return get(treeeven, 1, 0, treesize - 1, (l + 1) / 2, r / 2);
}

inline pair<int, ll> getodd(int l, int r)
{
    return get(treeodd, 1, 0, treesize - 1, l / 2, r / 2 - (1 - r % 2));
}

inline void add(int l, pair<int, ll> res)
{
//     cout << "add " << l << ' ' << res.fi << ' ' << res.se << endl;
    answer += res.se - (ll)(l - 1) * res.fi;
}

int main()
{
    scanf("%d%d", &n, &m);
    ls.insert(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        l[i]--, r[i]--;
        begins[l[i]].pb(i);
        ends[r[i]].pb(i);
        ls.insert(l[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 1) treeodd[treesize + i / 2] = {0, 1, i};
        else treeeven[treesize + i / 2] = {0, 1, i};
    }
    for (int i = treesize - 1; i > 0; i--)
    {
        update(treeodd, i);
        update(treeeven, i);
    }
    for (int t = 0; t < n; t++)
    {
        if ((r[t] - l[t] + 1) % 2 == 0)
        {
            addeven(r[t] + 1, m, 1); // pb : m -> n
            addodd(r[t] + 1, m, 1); // pb : m -> n
        }
        if (l[t] % 2 == 0) addodd(l[t], r[t], 1);
        else addeven(l[t], r[t], 1);
    }
    banfrom[0].insert(m);
    banfrom[1].insert(m); // pb: m->n
    answer = 0;
    int maxr = -1;
    for (int curl = 0; curl < m; curl++)
    {
//         cout << "curl = " << curl  << endl;
//         for (auto t : banfrom[curl % 2]) cout << t << ' ';
//         cout << endl;
        int start = *ls.lower_bound(curl);
        if (maxr >= curl) start = curl;
        int canevenfrom = start;
        int canoddfrom = start;
        int canto = *banfrom[curl % 2].begin() - 1;
        if (curl % 2 == 0) canoddfrom = max(canoddfrom, maxr + 1);
        else canevenfrom = max(canevenfrom, maxr + 1);
//         cout << canevenfrom << ' ' << canoddfrom << ' ' << canto << endl;
        add(curl, geteven(canevenfrom, canto));
        add(curl, getodd(canoddfrom, canto));
        for (auto t : begins[curl])
        {
            if ((r[t] - l[t] + 1) % 2 == 0)
            {
                addeven(r[t] + 1, m, -1); // pb : m -> n
                addodd(r[t] + 1, m, -1); // pb : m -> n
                banfrom[curl % 2].insert(r[t] + 1);
            } else
            {
//                 cout << "insert " << ' ' << 1 - curl % 2 << ' ' << r[t] + 1 << endl;
                banfrom[1 - curl % 2].insert(r[t] + 1);
            }
            if (l[t] % 2 == 0) addodd(l[t], r[t], -1);
            else addeven(l[t], r[t], -1);
            maxr = max(maxr, r[t]);
        }
        for (auto t : ends[curl])
        {
            if ((r[t] - l[t] + 1) % 2 == 0)
            {
                banfrom[l[t] % 2].erase(banfrom[l[t] % 2].find(r[t] + 1));
            } else
            {
                banfrom[1 - l[t] % 2].erase(banfrom[1 - l[t] % 2].find(r[t] + 1));
            }
        }
//         cout << "answer = " << answer << endl;
    }
    cout << answer << endl;
    return 0;
}