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
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>

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

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e5 + 15, base = 1e9 + 7;
const ll llinf = 2e18;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0) {
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL * binpow(n, s - 1) * n) % base;
    }
}

int timeA[maxn], timeD[maxn];
vector<pair<int, int> > Query, tree[4 * maxn], convHull;

pii line[maxn];

void add(int v, int tl, int tr, int l, int r, pii& curL) {
    if (l > r)
        return;
    if (tl == l && tr == r) {
        tree[v].pb(curL);
        return;
    }
    int tm = (tl + tr) >> 1;
    add(v << 1, tl, tm, l, min(r, tm), curL);
    add(v << 1|1, tm + 1, tr, max(l, tm + 1), r, curL);
}

pair<int, int>& Back() {
    return convHull.back();
}

pair<int, int>& afterB() {
    return convHull[convHull.size() - 2];
}

void build(int v, int tl, int tr) {
    sort(tree[v].begin(), tree[v].end());
    convHull.clear();

    for (auto cur:tree[v]) {
        while (convHull.size() > 0 && Back().first == cur.first)
            convHull.pop_back();
        while (convHull.size() > 1 && 1LL * (cur.first - afterB().first) * (Back().second - afterB().second)
                                   <= 1LL * (cur.second - afterB().second) * (Back().first - afterB().first))
            convHull.pop_back();
        convHull.pb(cur);
    }

    tree[v].clear();
    tree[v] = convHull;

    if (tl == tr) {
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1|1, tm + 1, tr);
}

ll CHT_query(int v, int x) {
    if (tree[v].empty())
        return -1LL * llinf;
    if (tree[v].size() == 1)
        return 1LL * tree[v][0].first * x + tree[v][0].second;

    int l = 0, r = tree[v].size() - 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (1LL * tree[v][m].first * x + tree[v][m].second >=
            1LL * tree[v][m + 1].first * x + tree[v][m + 1].second)
            r = m;
        else
            l = m;
    }

    return max(1LL * tree[v][l].first * x + tree[v][l].second,
               1LL * tree[v][r].first * x + tree[v][r].second); 
}

ll query(int v, int tl, int tr, int curTime, int x) {
    // cout << v << ' ' << tl << ' ' << tr << endl;
    if (tl == tr) {
        return CHT_query(v, x);
    }
    int tm = (tl + tr) >> 1;
    if (curTime <= tm)
        return max(CHT_query(v, x), query(v << 1, tl, tm, curTime, x));
    return max(CHT_query(v, x), query(v << 1|1, tm + 1, tr, curTime, x));
}

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++)
        timeA[i] = -1, timeD[i] = n - 1;

    for (int i = 0; i < n; i++) {
        int type;
        read(type);

        if (type == 1) {
            int k, b;
            read(k, b);

            timeA[i] = i;
            line[i] = {k, b};
        }

        if (type == 2) {
            int pos;
            read(pos);
            pos--;

            timeD[pos] = i - 1;
        }

        if (type == 3) {
            int q;
            read(q);

            Query.pb(mp(q, i));
        }
    }

    for (int i = 0; i < n; i++)
        if (timeA[i] != -1) {
            add(1, 0, n, timeA[i], timeD[i], line[i]);
        }
    build(1, 0, n);
    for (auto i:Query) {
        int x = i.first, curTime = i.second;

        ll res = query(1, 0, n, curTime, x);
        if (res == -1LL * llinf)
            puts("EMPTY SET");
        else
            printf("%I64d\n", res);
    }
    return 0;
}