#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, m;
int k[MAXN], lo[MAXN][2], hi[MAXN][2], len[MAXN][2];
int dp[MAXN][2], doso[MAXN][2], sol[MAXN];
set <pi> st[2];
set <int> akt[2];

void calc () {
    len[0][0] = len[0][1] = 1;
    st[0].insert({0, 0});
    st[1].insert({0, 0});
    akt[0].insert(0);
    akt[1].insert(0);
    for (int i = 1; i <= n; i++) {
        for (int tip = 0; tip < 2; tip++) {
            while (!st[tip].empty()) {
                auto it = st[tip].begin();
                if ((it -> first) >= lo[i][tip]) break;
                int ind = it -> second;
                akt[tip].erase(ind);
                st[tip].erase(it);
            }
            while (!st[tip].empty()) {
                auto it = st[tip].end(); it--;
                if ((it -> first) <= hi[i][tip]) break;
                int ind = it -> second;
                akt[tip].erase(ind);
                st[tip].erase(it);
            }
        }
        for (int tip = 0; tip < 2; tip++) {
            if (!(lo[i][tip] <= k[i] && k[i] <= hi[i][tip])) continue;
            len[i][tip] = 1 + len[i - 1][tip];

            auto it = akt[!tip].lower_bound(i - len[i][tip]);
            if (it != akt[!tip].end() && *it < i) {
                dp[i][tip] = 1;
                doso[i][tip] = *it;
                st[tip].insert({k[i], i});
                akt[tip].insert(i);
            }
        }
    }
}

void reconstruct (int pos, int tip) {
    while (pos != 0) {
        int prv = doso[pos][tip];
        for (int i = prv + 1; i <= pos; i++) {
            sol[i] = tip;
        }
        pos = prv;
        tip = !tip;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> lo[i][0] >> hi[i][0] >> lo[i][1] >> hi[i][1];
    }
    calc();
    if (dp[n][0]) {
        reconstruct(n, 0);
    } else if (dp[n][1]) {
        reconstruct(n, 1);
    } else {
        cout << "No";
    }
    return 0;
}