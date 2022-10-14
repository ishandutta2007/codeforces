#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200010;

int n, m;
int a[MAXN], fen[MAXN], sol[MAXN];
vector < pair <int, int> > v;
vector < pair <int, int> > q[MAXN];

void ubaci (int x, int k) {
    for (; x < MAXN; x += x&-x) fen[x] += k;
}

int kth (int k) {
    int pos = 0, cnt = 0;
    for (int i = 17; i >= 0; i--) {
        int novi = pos + (1 << i);
        if (novi < MAXN && cnt + fen[novi] < k) pos = novi, cnt += fen[novi];
    }
    return pos + 1;
}

void rjesi () {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int ind = v[i].second;
        ubaci(ind, 1);
        for (auto par : q[i + 1]) {
            int upt = par.first, pos = par.second;
            sol[upt] = kth(pos);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back({ -a[i], i});
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, pos;
        cin >> k >> pos;
        q[k].push_back({i, pos});
    }
    rjesi();
    for (int i = 0; i < m; i++) {
        cout << a[sol[i]] << '\n';
    }
    return 0;
}