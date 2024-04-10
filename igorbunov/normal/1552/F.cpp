#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

int t[5000000];
int mas[5000000];

int MOD = 998244353;

void push(int v, int vl, int vr) {
    int vm = (vl + vr) / 2;
    mas[v] %= MOD;
    if (v * 2 + 1 < 5000000) {
        mas[v * 2 + 1] += mas[v];
        mas[v * 2 + 1] %= MOD;
    }
    if (v * 2 + 2 < 5000000) {
        mas[v * 2 + 2] += mas[v];
        mas[v * 2 + 2] %= MOD;
    }
    t[v] += (int)(vr - vl) * mas[v];
    t[v] %= MOD;
    mas[v] = 0;
}

int all_sum(int v, int l, int r, int vl, int vr) {
    push(v, vl, vr);
    if (l >= r) {
        return 0;
    }
    if (l == vl && r == vr) {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    int sum1 = all_sum(v * 2 + 1, l, min(r, vm), vl, vm);
    int sum2 = all_sum(v * 2 + 2, max(l, vm), r, vm, vr);
    return ((sum1 + sum2) % MOD);
}

void update(int v, int l, int r, int vl, int vr, int val) {
    val %= MOD;
    push(v, vl, vr);
    if (l >= r) {
        return;
    }
    if (l == vl && r == vr) {
        mas[v] += val;
        mas[v] %= MOD;
        push(v, vl, vr);
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2 + 1, l, min(r, vm), vl, vm, val);
    update(v * 2 + 2, max(l, vm), r, vm, vr, val);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    t[v] %= MOD;
}

int prev_1[500000];
int turn_on[500000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> all;
    vector<pair<pair<int, int>, int>> arr1;
    all.push_back(0);
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        arr1.push_back(make_pair(make_pair(x, y), s));
        all.push_back(x);
        all.push_back(y);
    }
    sort(all.begin(), all.end());
    all.push_back(all.back() + 1);
    map<int, int> real;
    for (int i = 0; i < all.size(); i++) {
        real[all[i]] = i;
    } 
    for (int i = 0; i < 500000; i++) {
        prev_1[i] = -1;
        turn_on[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x = real[arr1[i].first.first];
        int y = real[arr1[i].first.second];
        int s = arr1[i].second;
        turn_on[x] = s;
        prev_1[x] = y;
    }
    int N = 2 * n + 2;
    update(0, 0, 1, 0, N, all[1]);
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (prev_1[i] == -1) {
            ans += all[i] - all[i - 1];
            ans %= MOD;
            update(0, 0, i + 1, 0,  N, all[i + 1] - all[i]);
        } else {
            int val = all_sum(0, prev_1[i], prev_1[i] + 1, 0, N);
            if (turn_on[i]) {
                ans += val;
            }
            ans += all[i] - all[i - 1];
            ans %= MOD;
            update(0, 0, i + 1, 0, N, val + all[i + 1] - all[i]);
        }
    }
    cout << ans;
}