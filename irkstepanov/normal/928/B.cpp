#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

/*struct node {
    int promise;
    int sum;
    node() : promise(0), sum(0) {}
};

vector<node> t;

void upd(int v, int tl, int tr) {
    t[v].sum = tr - tl + 1;
    t[v].promise = 1;
}

void push(int v, int tl, int tr) {
    if (t[v].promise == 0) {
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v * 2, tl, tm);
    upd(v * 2 + 1, tm + 1, tr);
    t[v].promise = 0;
}

void assign(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        t[v].sum = tr - tl + 1;
        t[v].promise = 1;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        assign(v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        assign(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    if (k >= n) {
        k = n - 1;
    }

    vector<int> lst(n), ans(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    lst[0] = k;
    ans[0] = k + 1;
    for (int i = 1; i < n; ++i) {
        if (p[i] == -1) {
            lst[i] = min(n - 1, i + k);
            int x = max(0, i - k);
            ans[i] = lst[i] - x + 1;
            continue;
        }
        int x = max(0, i - k);
        lst[i] = min(n - 1, i + k);
        if (x >= lst[p[i]] + 1) {
            ans[i] = ans[p[i]] + (lst[i] - x + 1);
        } else {
            ans[i] = ans[p[i]] + lst[i] - lst[p[i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}