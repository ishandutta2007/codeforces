#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, cnt;
set <int> st[MAXN];
vector <int> v;

int broji (int val, int ind) {
    int res = 0;
    auto it = st[ind].find(val);
    if (it != st[ind].begin()) {
        it--;
        if (*it == val - 1) res++;
        it++;
    }
    it++;
    if (it != st[ind].end()) {
        if (*it == val + 1) res++;
    }
    return res;
}

void ubaci (int val, int ind) {
    st[ind].insert(val);
    cnt += broji(val, ind);
}

void spoji (int a, int b) {
    if (st[b].size() > st[a].size()) swap(st[a], st[b]);
    v.clear();
    int br = 0;
    for (auto x : st[b]) {
        if (!v.empty() && v.back() + 1 == x) br++;
        v.push_back(x);
    }
    cnt -= br;
    for (auto x : v) ubaci(x, a);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int ind; cin >> ind;
        ubaci(i, ind);
    }
    cout << n - 1 - cnt << '\n';
    for (int i = 0; i < m - 1; i++) {
        int a, b;
        cin >> a >> b;
        spoji(a, b);
        cout << n - 1 - cnt << '\n';
    }
    return 0;
}