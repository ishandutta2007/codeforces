#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCjjjjjjjC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;

template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

vc<pr<int, int>> psave[MAXN];
int sizes[MAXN];
int p[MAXN];

int find_dsu(int v){
    if (v == p[v]){
        return v;
    }
    return find_dsu(p[v]);
}

bool merge_dsu(int u, int v, int times){
    u = find_dsu(u);
    v = find_dsu(v);
    if (u != v){
        if (sizes[u] < sizes[v]){
            swap(u, v);
        }
        p[v] = u;
        psave[v].pb({times, u});
        sizes[u] += sizes[v];
        return 1;
    }
    return 0;
}

int find_dsu(int v, int times){
    int p = (*prev(upper_bound(all(psave[v]), mp(times, INF)))).sc;
    if (p == v){
        return v;
    }
    return find_dsu(p, times);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vc<pr<pr<int, int>,pr <int, int>>> a(m);
    vc<int> ans(m, -1);
    for (int i = 0; i < m; i++){
        cin >> a[i].sc.fs >> a[i].sc.sc >> a[i].fs.fs;
        a[i].sc.fs--, a[i].sc.sc--;
        a[i].fs.sc = i;
    }
    sort(all(a));
    for (int i = 0; i < n; i++){
        p[i] = i;
        sizes[i] = 1;
        psave[i] = {{0, i}};
    }
    for (int i = 0; i < m; i++){
        if (!merge_dsu(a[i].sc.fs, a[i].sc.sc, i + 1)) {
            int l = -1;
            int r = i;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if (find_dsu(a[i].sc.fs, mid + 1) != find_dsu(a[i].sc.sc, mid + 1)){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            ans[a[i].fs.sc] = a[r].fs.fs;
        }
    }
    for (int i = 0; i < m; i++){
        if (ans[i] != -1){
            cout << ans[i] << ' ';
        }
    }
}