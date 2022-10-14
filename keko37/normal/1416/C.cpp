#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 300005;

int n;
int fen[MAXN];
pi sol[35];
vector <pi> v;

void ubaci (int x, int k) {
    for (; x < MAXN; x += x&-x) fen[x] += k;
}

int upit (int x) {
    int res = 0;
    for (; x > 0; x -= x&-x) res += fen[x];
    return res;
}

void solve (int lo, int hi, int b) {
    if (lo > hi) return;
    int mid = hi + 1;
    for (int i = lo; i <= hi; i++) {
        if (v[i].first & (1 << b)) {
            mid = i;
            break;
        }
    }
    if (b > 0) {
        solve(lo, mid - 1, b - 1);
        solve(mid, hi, b - 1);
    }
    int br = 0;
    for (int i = lo; i < mid; i++) {
        ubaci(v[i].second, 1);
        br++;
    }
    for (int i = mid; i <= hi; i++) {
        int res = upit(v[i].second);
        sol[b].first += br - res;
        sol[b].second += res;
    }
    for (int i = lo; i < mid; i++) {
        ubaci(v[i].second, -1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    solve(0, n - 1, 30);
    llint uk = 0, x = 0;
    for (int i = 0; i <= 30; i++) {
        if (sol[i].first <= sol[i].second) {
            uk += sol[i].first;
        } else {
            uk += sol[i].second;
            x += 1 << i;
        }
    }
    cout << uk << " " << x;
    return 0;
}