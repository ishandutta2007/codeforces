#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 322;
vector<int> g[N], gt[N];
int a[N];
int used[N];
int cycle[N];
int num[N], who[N];

vector<int> b;
void dfs(int x, int pos) {
    num[x] = pos;
    who[pos] = x;
    used[x] = true;
    for (int y : g[x]) {
        if (!used[y]) {
            dfs(y, pos + 1);
        } else {
            for (int i = num[y]; i <= pos; ++i) {
                b.push_back(who[i]);
                cycle[b.back()] = true;
            }
        }
    }
}

ll gcd(ll a, ll b) {
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int f[N];
void dfs2(int x, int h) {
    used[x] = true;
    f[x] = h;
    for (int y : gt[x]) {
        if (!cycle[y]) {
            dfs2(y, h + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
        g[i].push_back(a[i]);
        gt[a[i]].push_back(i);
    }

    ll ans = 1;
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            b.clear();
            dfs(i, 0);
            for (int x : b)
                dfs2(x, 0);
            ans = lcm(ans, b.size());
        }
    ll was = ans;
    for (int i = 0; i < n; ++i) {
        while (f[i] > ans) ans += was;
    }

    cout << ans << endl;

    return 0;
}