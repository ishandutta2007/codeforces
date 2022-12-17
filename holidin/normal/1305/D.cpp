#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 1005 + 1;

vector <int> e[N];

void del(int a, int b) {
    for (int i = 0; i < e[a].size(); ++i)
    if (e[a][i] == b) {
        swap(e[a][i], e[a].back());
        e[a].pop_back();
        break;
    }
    swap(a, b);
    for (int i = 0; i < e[a].size(); ++i)
    if (e[a][i] == b) {
        swap(e[a][i], e[a].back());
        e[a].pop_back();
        break;
    }
}

void do_quer(int a, int b) {
    cout << "? " <<  a << ' ' << b << endl;
}


int get_ans() {
    int x;
    cin >> x;
    return x;
}

void retans(int x) {
    cout << "! " << x << endl;
    exit(0);
}

vector <int> v;

void dfs(int u) {
    while (e[u].size() >= 2) {
        do_quer(e[u][0], e[u][1]);
        int ans = get_ans();
        if (ans == u) {
            del(u, e[u][1]);
            del(u, e[u][0]);
        } else {
            del(u, ans);
            v.clear();
            dfs(ans);
        }
    }
    v.push_back(u);
    if (e[u].size() == 1) {
        int x = e[u][0];
        del(x, u);
        dfs(x);
    }
    int i;
    for (i = (int) v.size() - 1; i >= 2; i -= 2) {
        do_quer(v[i - 2], v[i]);
        int ans = get_ans();
        if (ans != v[i - 2]) {
            retans(ans);
        }
    }
    if (i == 0) {
        retans(v[0]);
    }
    do_quer(v[0], v[1]);
    retans(get_ans());
}

void solve() {
    int i, j, n, a, b;
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);
}

signed main() {
    #ifdef local
        //freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}