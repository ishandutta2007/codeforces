#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int SIZ = 35000;

int n, m, p, mx;
llint val[MAXN], sol;
int cnt[SIZ], sum[SIZ];
vector <int> v;

void check (int ind) {
    v.clear();
    for (int i = 0; i < m; i++) {
        if (val[ind] & (1LL << i)) v.push_back(i);
    }
    p = v.size();
    if (p == 0) return;

    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        int br = 0;
        for (int j = 0; j < v.size(); j++) {
            if (val[i] & (1LL << v[j])) {
                br += 1 << j;
            }
        }
        cnt[br ^ ((1 << p) - 1)]++;
    }

    for (int i = 0; i < (1<<p); i++) {
        sum[i] = cnt[i];
    }
    for (int i = 0; i < p; i++) {
        for (int mask = 0; mask < (1<<p); mask++) {
            if (mask & (1 << i)) {
                sum[mask] += sum[mask ^ (1 << i)];
            }
        }
    }

    int best = -1;
    for (int mask = 0; mask < (1 << p); mask++) {
        if (sum[mask ^ ((1 << p) - 1)] * 2 >= n && __builtin_popcount(mask) > mx) {
            mx = __builtin_popcount(mask);
            best = mask;
        }
    }

    if (best != -1) {
        sol = 0;
        for (int i = 0; i < p; i++) {
            if (best & (1 << i)) {
                sol ^= 1LL << v[i];
            }
        }
    }
}

bool ok () {
    int br = 0;
    for (int i = 1; i <= n; i++) {
        if ((val[i] & sol) == sol) br++;
    }
    return br * 2 >= n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    srand(time(0) * getpid());
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        llint br = 0;
        for (auto c : s) {
            br *= 2;
            if (c == '1') br++;
        }
        val[i] = br;
    }
    for (int i = 1; i <= 40; i++) {
        int pos = uniform_int_distribution<int>(1, n)(rng);
        check(pos);
    }
    for (int i = m-1; i >= 0; i--) {
        cout << !!(sol & (1LL << i));
    }
    //cout << endl;
   // cout << ok();
    return 0;
}