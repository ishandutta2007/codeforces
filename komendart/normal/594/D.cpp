#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int maxw = 1e6 + 1;
const int maxn = 2e5 + 2;

int power(int a, int p) {
    if (p == 0) return 1;
    if (p % 2 == 1) return power(a, p - 1) * a % MOD;
    return power(a * a % MOD, p / 2);
}

int inverse(int x) {
    return power(x, MOD - 2);
}

vector<int> tree(maxn, 1);

void inc(int p, int v) {
    for (int i = p; i < maxn; i |= i + 1) {
        tree[i] = tree[i] * v % MOD;
    }
}

int get(int p) {
    int result = 1;
    for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
        result = result * tree[i] % MOD;
    }
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        inc(i, a[i]);
    }

    vector<int> factorize(maxw);
    for (int i = 2; i < maxw; i++) {
        if (!factorize[i]) {
            for (int j = i; j < maxw; j += i) {
                factorize[j] = i;
            }
        }
    }
    vector< vector<int> > pos(maxw, vector<int>());
    for (int i = n; i >= 1; i--) {
        for (int t = a[i]; t > 1;) {
            int p = factorize[t];
            pos[p].push_back(i);
            while (t % p == 0) t /= p;
        }
    }
    for (int i = 0; i < maxw; i++) {
        if (!pos[i].empty()) {
            inc(pos[i].back(), (i - 1) * inverse(i) % MOD);
        }
    }

    int m;
    cin >> m;
    vector< vector< pair<int, int> > > queries(n + 1);
    for (int i = 0; i < m; i++) {
        int left, right; cin >> left >> right;
        queries[left].push_back({right, i});
    }

    vector<int> answer(m);
    for (int i = 1; i <= n; i++) {
        for (auto &p: queries[i]) {
            answer[p.second] = get(p.first);
        }
        for (int t = a[i]; t > 1;) {
            int p = factorize[t];
            pos[p].pop_back();
            if (!pos[p].empty()) {
                inc(pos[p].back(), (p - 1) * inverse(p) % MOD);
            }
            while (t % p == 0) t /= p;
        }
        inc(i, inverse(get(i)));
    }

    for (auto i: answer) {
        cout << i << '\n';
    }
}