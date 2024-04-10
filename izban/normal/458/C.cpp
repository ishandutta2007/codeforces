#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 100200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int a[maxn], b[maxn];
vector<int> v[maxn], all;

bool ok(int x) {
    int cc = v[0].size();
    for (int i = 1; i < maxn; i++) if (v[i].size() >= x) cc += (int)v[i].size() - x + 1;
    return cc <= x;
}

bool cmp(int i, int j) {
    return v[i].size() < v[j].size() || v[i].size() == v[j].size() && i < j;
}

int cnt[4 * maxn];
ll sum[4 * maxn];

void add(int v, int tl, int tr, int x) {
    if (tl == tr) {
        cnt[v]++;
        sum[v] += x;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (x <= tm) add(v * 2, tl, tm, x);
    else add(v * 2 + 1, tm + 1, tr, x);
    cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
}

ll get(int v, int tl, int tr, int k) {
    if (k <= 0) return 0;
    if (tl == tr && cnt[v] > k) {
        return 1LL * k * tl;
    }
    if (cnt[v] <= k) {
        return sum[v];
    }
    int tm = (tl + tr) >> 1;
    return get(v * 2, tl, tm, k) + get(v * 2 + 1, tm + 1, tr, k - cnt[v * 2]);
}

void Unique(vector<int> &v) {
    vector<int> res;
    for (int l = 0; l < (int)v.size(); l++) {
        int r = l;
        while (r + 1 < (int)v.size() && v[r + 1] == v[l]) r++;
        res.push_back(v[l]);
        l = r;
    }
    v = res;
}

ll fastsolve() {
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < maxn; i++) v[i].clear();
        all.clear();
        for (int i = 0; i < n; i++) {
            v[a[i]].push_back(b[i]);
            if (a[i]) all.push_back(a[i]);
        }
        for (int i = 0; i < maxn; i++) sort(v[i].begin(), v[i].end());
        sort(all.begin(), all.end(), cmp);
        //all.resize(unique(all.begin(), all.end()) - all.begin());
        Unique(all);
        
        int l = 1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (ok(m)) r = m;
            else l = m;
        }
        int mn = r;
        //int mn = 1;
        
        ll ans = 1e18;
        ll cres = 0;
        int ccnt = 0;
        for (int i = 1; i < maxn; i++) {
            for (int j = 0; j < (int)v[i].size() - mn + 1; j++) {
                cres += v[i][j];
                ccnt++;
            }
            for (int j = max((int)v[i].size() - mn + 1, 0); j < (int)v[i].size(); j++) {
                add(1, 0, maxn - 1, v[i][j]);
            }
        }
        ans = min(ans, cres + get(1, 0, maxn - 1, mn - ccnt - (int)v[0].size()));
        while (mn < n) {
            for (int i = (int)all.size() - 1; i >= 0 && v[all[i]].size() >= mn; i--) {
                int id = (int)v[all[i]].size() - mn;
                cres -= v[all[i]][id];
                ccnt--;
                add(1, 0, maxn - 1, v[all[i]][id]);
            }
            mn++;
            ans = min(ans, cres + get(1, 0, maxn - 1, mn - ccnt - (int)v[0].size()));
        }
        return ans;
        //cout << ans << endl;
}

ll slowsolve() {
    ll ans = 1e18;
    for (int mask = 0; mask < 1 << n; mask++) {
        ll cres = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) if (a[i] == 0 || mask & (1 << i)) cnt++;
        for (int i = 0; i < n; i++) if (mask & (1 << i)) cres += b[i];
        vector<int> v(100);
        for (int i = 0; i < n; i++) if (!(mask & (1 << i))) v[a[i]]++;
        bool ok = 1;
        for (int i = 1; i < 100; i++) ok &= v[i] < cnt;
        if (ok) ans = min(ans, cres);
    }
    return ans;
}

void gen() {
    n = rand() % 5 + 1;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
        b[i] = rand() % 100;
    }
}

void stress(bool f) {
    if (!f) return;
    for (int it = 0;; it++) {
        cerr << it << endl;
        gen();
        ll ans1 = fastsolve();
        ll ans2 = slowsolve();
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) cout << a[i] << " " << b[i] << endl;
            fastsolve();
            break;
        }
    }
    exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    stress(0);
    
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        cout << fastsolve() << endl;
    }
    return 0;
}