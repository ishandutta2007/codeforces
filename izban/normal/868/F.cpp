#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 4e18;

const int N = 1 << 17;

int n;
int a[N];
ll dp[N], ndp[N];

/*ll cost(int l, int r) {
    vector<int> cnt(n);
    ll ans = 0;
    for (int i = l; i <= r; i++) {
        ans += cnt[a[i]]++;
    }
    return ans;
}*/

int cnt[N];
ll curCost = 0;

ll cost() {
    return curCost;
}

void add(int id) {
    curCost += cnt[a[id]]++;
}

void del(int id) {
    curCost -= --cnt[a[id]];
}

void addSeg(int L, int R) {
    for (int i = L; i <= R; i++) add(i);
}

void delSeg(int L, int R) {
    for (int i = L; i <= R; i++) del(i);
}

// added everything (optR; l)
void rec(int l, int r, int optL, int optR) {
    if (l > r) return;
    int m = (l + r) >> 1;

    ll val = INF;
    int wh = -1;

    addSeg(max(l, optR + 1), m - 1);
    for (int i = min(optR, m - 1); i >= optL; i--) {
        add(i);
        ll cur = dp[i] + cost();
        if (val > cur) {
            val = cur;
            wh = i;
        }
    }
    delSeg(optL, min(optR, m - 1));
    delSeg(max(l, optR + 1), m - 1);

    assert(ndp[m] >= val);
    ndp[m] = val;


    addSeg(wh + 1, min(optR, l - 1));
    rec(l, m - 1, optL, wh);
    delSeg(wh + 1, min(optR, l - 1));


    addSeg(max(l, optR + 1), m);
    rec(m + 1, r, wh, optR);
    delSeg(max(l, optR + 1), m);
    /*for (int i = optL; i <= min(optR, m - 1); i++) {
        ll cur = dp[i] + cost(i, m - 1);
        if (val > cur) {
            val = cur;
            wh = i;
        }
    }*/
}

ll fast(vector<int> _a, int k) {
    n = _a.size();
    for (int i = 0; i < n; i++) a[i] = _a[i];


    for (int i = 0; i <= n; i++) dp[i] = INF;
    dp[0] = 0;

    for (int j = 0; j < k; j++) {
        for (int i = 0; i <= n; i++) ndp[i] = dp[i];

        rec(1, n, 0, n);

        for (int i = 0; i <= n; i++) dp[i] = ndp[i];
    }
    return dp[n];
}

ll slow(vector<int> a, int k) {
    int n = a.size();

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int j = 0; j < k; j++) {
        vector<ll> ndp = dp;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(n);
            ll cost = 0;
            for (int j = i; j < n; j++) {
                cost += cnt[a[j]]++;
                ndp[j + 1] = min(ndp[j + 1], dp[i] + cost);
            }
        }
        dp = ndp;
    }
    return dp[n];
}

pair<int, vector<int> > gen(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand() % n;
    int k = rand() % n + 1;
    return make_pair(k, a);
}

void stress() {
    for (int it = 0; it <= 1e5; it++) {
        srand(it);
        cout << it << endl;

        int n = rand() % 50 + 1;
        auto o = gen(n);
        auto a = o.second;
        int k = o.first;

        ll ans1 = fast(a, k);
        ll ans2 = slow(a, k);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << " " << k << endl;
            for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
            cout << endl;
            //fast(a, k);
            exit(0);
        }
    }
}

void test() {
    int n = 1e5;
    auto a = gen(n).second;
    int k = 20;
    cout << fast(a, k) << endl;
    cout << clock() / (double)CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();
    //test();

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        printf("%lld\n", fast(a, k));
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}