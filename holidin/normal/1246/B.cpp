#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e5 + 1;

vector <pair<int, int> > v[N];
int cnt[N], a[N];
int all_ans = 0;


void pruf(vector <pair<int, int> > &v, int n) {
    int x = 1;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].se; ++j)
            x *= v[i].fi;
    }
    if (x < 0)
        exit(1);
    if (n / x >= x && x < N && n / x < N) {
        all_ans += cnt[x] * cnt[n / x];
        if (x * x == n) {
            all_ans -= cnt[x] * cnt[x] - (cnt[x] * (cnt[x] - 1)) / 2;
        }
    }
}

void add(vector <pair<int, int> > &v, vector <pair<int, int> > &mx, int k) {
    int i = 0;
    while (v[i].se == mx[i].se * k) {
        v[i].se = 0;
        ++i;
    }
    ++v[i].se;
}

int bp(int x, int k) {
    int ans = 1;
    for (int i = 0; i < k; ++i)
        ans *= x;
    return ans;
}

void solve() {
    int i, j, k, n;
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (i = 2; i < N; ++i)
    if (v[i].size() == 0) {
        v[i].push_back({i, 1});
        for (j = 2; i * j < N; ++j) {
            int x = j, cnt = 1;
            while (x % i == 0) {
                x /= i;
                ++cnt;
            }
            v[i * j].push_back({i, cnt});
        }
    }
    all_ans = 0;
    for (i = 1; i < N && (i < 2 || k < 40) && bp(i, k) <= 1e10 + 1; ++i) {
        vector <pair<int, int> > tek = v[i];
        int cnt = 1;
        for (j = 0; j < tek.size(); ++j) {
            cnt *= (tek[j].se * k + 1);
            tek[j].se = 0;
        }
        pruf(tek, bp(i, k));
        for (int j = 1; j < cnt; ++j) {
            add(tek, v[i], k);
            pruf(tek, bp(i, k));
        }
    }
    cout << all_ans;
}


signed main() {
    int i, j, k, n, p, x;
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}