#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;
vector <int> v;
map <int, int> m;
set <int> s;
int a[N], p;
bool inv = 0;

set <int> g;
void pruf(int x) {
    if (g.find(x) == g.end())
        g.insert(x);
    else
        return;
    set <int> f;
    int a = v[0], b = v[0];
    while (s.find(b) != s.end()) {
        f.insert(b);
        b = (b + x) % p;
    }
    while (s.find(a) != s.end()) {
        f.insert(a);
        a = (a + p - x) % p;
    }
    if (f.size() == v.size()) {
        if (inv)
            cout << b << ' ' << x << endl;
        else
            cout << (a + x) % p << ' ' << x << endl;
        exit(0);
    }
}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> p >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    bool same = true;
    for (i = 1; i < n; ++i)
    if (a[i] != a[i - 1])
        same = false;
    if (same) {
        cout << a[0] << ' ' << 1 << endl;
        exit(0);
    }
    int cicl = 0;
    for (i = 0; i < n; ++i)
        ++m[a[i]];
    if (p <= 2e5) {
        int mn = 1e9;
        for (i = 0; i < p; ++i)
            mn = min(m[i], mn);
        for (i = 0; i < p; ++i)
            m[i] -= mn;
        same = true;
        for (i = 0; i < p; ++i)
        if (m[i] != 0)
            same = false;
        if (same) {
            cout << 0 << ' ' << 1 << endl;
            exit(0);
        }
    }
    int cnt = 0;
    for (map<int, int> :: iterator it = m.begin(); it != m.end(); ++it)
    if ((*it).second >= 2) {
        cout << -1;
        return 0;
    } else if ((*it).second == 1)
            ++cnt;
    if (cnt > p / 2) {
        inv = 1;
        for (i = 0; i < p; ++i)
        if (m[i] == 0)
            v.push_back(i);
    } else
        for (map<int, int> :: iterator it = m.begin(); it != m.end(); ++it)
        if ((*it).second == 1)
            v.push_back((*it).first);
    if (cnt == 1) {
        cout << v[0] << ' ' << 1;
        exit(0);
    }
    if (cnt == p - 1) {
        cout << (v[0] + 1) % p << ' '<< 1 << endl;
        exit(0);
    }
    for (i = 0; i < v.size(); ++i)
        s.insert(v[i]);
    for (i = 0; i < 8e5; ++i) {
        int x = ((int)rand() + (int)rand()) % v.size(), y = ((int)rand() + (int)rand()) % v.size();
        if (v[x] != v[y])
            pruf((v[x] - v[y] + p) % p);
    }
    cout << -1;
}