#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("connect.out","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
// #include <unordered_map>
// #include <unordered_set>

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';

    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }

    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e6 + 5, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

vector<pair<int, int> > tree[4 * maxn];

void add(int v, int tl, int tr, int l, int r, pair<int, int> q) {
    if (l > r)
        return;
    if (tl == l && tr == r) {
        tree[v].pb(q);
    } else {
        int tm = (tl + tr) >> 1;
        add(v << 1, tl, tm, l, min(r, tm), q);
        add(v << 1|1, tm + 1, tr, max(l, tm + 1), r, q);
    }
}

vector<pair<int, int> > * changes;
struct Dsu
{
    vector<int> parent, _rank;

    int comp, n;

    void make_set(int v) {
        parent[v] = v;
        _rank[v] = 1;
    }

    Dsu() {}
    Dsu(int _n) {
        n = _n;
        comp =  n;

        parent.resize(n);
        _rank.resize(n);

        for (int i = 0; i < n; i++)
            make_set(i);
    }

    int find_set (int v) {
        if (v == parent[v])
            return v;
        changes->pb(mp(v, parent[v]));
        return parent[v] = find_set(parent[v]);
    }

    void union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            comp--;
            if (_rank[a] < _rank[b])
                swap (a, b);
            changes->pb(mp(b, parent[b]));
            parent[b] = a;
            
            changes->pb(mp(a, -_rank[a]));
            _rank[a] += _rank[b];
        }
    }
};

Dsu dsu;

int answer[maxn];
void dfs(int v, int tl, int tr) {
    vector<pair<int, int> > recent;
    changes = &recent;

    for (auto i:tree[v]) {
        int f = i.f, t = i.s;
        if (t >= 0)
            dsu.union_sets(f, t);
    }

    for (auto i:tree[v]) {
        int f = i.f, t = i.s;
        if (t < 0) {
            answer[f] = dsu._rank[dsu.find_set(-t - 1)];
        }
    }

    if (tl != tr) {
        int tm = (tl + tr) >> 1;
        dfs(v << 1, tl, tm);
        dfs(v << 1|1, tm + 1, tr);
    }


    reverse(all(recent));
    for (auto i:recent) {
        int pos, old;
        pos = i.f, old = i.s;

        if (old < 0)
            dsu._rank[pos] = -old;
        else
            dsu.parent[pos] = old;
    }
}

pair<int, int> edge[maxn];
bool isDeleted[maxn];

map<pii, list<int>> sot;

struct Query {
    char tp;
    int x, y;
    
    Query(char tp, int x, int y) : tp(tp), x(x), y(y) {}
};

void solve(const vector<Query>& query) {
    memset(answer, -1, sizeof(answer));

    int q = query.size();

    for (int i = 0; i < q; i++) {
        isDeleted[i] = 1;
        if (query[i].tp == '+') {
            isDeleted[i] = 0;
            int f = query[i].x, t = query[i].y;

            if (f > t)
                swap(f, t);

            sot[mp(f, t)].push_back(i);
            edge[i] = mp(f, t);
        }
        if (query[i].tp == '-') {
            int f = query[i].x, t = query[i].y;

            if (f > t)
                swap(f, t);

            int pos = sot[mp(f, t)].front();
            sot[mp(f, t)].pop_front();
            add(1, 0, q, pos, i, edge[pos]);

            isDeleted[pos] = 1;
        }
        if (query[i].tp == '?') {
            int f = query[i].x;
            add(1, 0, q, i, i, mp(i, -f - 1));
        }
    }

    for (int i = 0; i < q; i++)
        if (!isDeleted[i])
            add(1, 0, q, i, q, edge[i]);

    dfs(1, 0, q);
    for (int i = 0; i < q; i++)
        if (answer[i] != -1)
            printf("%d\n", answer[i]);
}

int main() {
    // files1;
    fast_io;

    int n, q, k;
    cin >> n >> q >> k;

    dsu = Dsu(n);

    vector<Query> res;
    vector<vector<Query>> days;
    int day = 0;

    days.emplace_back();
    for (int i = 0;  i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            days[day].push_back(Query('+', x, y));
            res.push_back(Query('+', x, y));
        }
        if (t == 2) {
            int z;
            cin >> z;
            z--;
            res.push_back(Query('?', z, -1));
        }
        if (t == 3) {
            if (day - k + 1 >= 0) {
                for (auto qq : days[day - k + 1]) {
                    qq.tp = '-';
                    res.push_back(qq);
                }
            }
            day++;
            days.emplace_back();
        }
    }

    solve(res);
    return 0;
}