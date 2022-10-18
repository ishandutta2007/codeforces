#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

int d[52][52][52][4];
int dnew[3][52][2501];
int dsum[2501];
int fact[52];
const int MOD = 1e9 + 7;

int sum(int a, int b) {
    if (a + b >= MOD) {
        return a + b - MOD;
    }
    return a + b;
}

int sum1(int a, int b) {
    if (a + b >= MOD * MOD) {
        return a + b - MOD * MOD;
    }
    return a + b;
}

int mul(int a, int b) {
    return (1ll * a * b) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<vector<int>> a(3);
    vector<int> counts(3);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        y--;
        a[y].push_back(x);
        counts[y]++;
    }
    if (counts[0] > counts[2]){
        swap(a[0], a[2]);
        swap(counts[0], counts[2]);
    }
    if (counts[0] > counts[1]){
        swap(a[0], a[1]);
        swap(counts[0], counts[1]);
    }
    d[0][0][0][3] = 1;
    fact[0] = 1;
    for (int i = 1; i <= 50; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    for (int i = 0; i <= counts[0]; i++) {
        for (int j = 0; j <= counts[1]; j++) {
            for (int k = 0; k <= counts[2]; k++) {
                for (int lasts = 0; lasts < 4; lasts++) {
                    for (int news = 0; news < 3; news++) {
                        if (lasts == news) {
                            continue;
                        }
                        if (news == 0) {
                            d[i + 1][j][k][news] = sum(d[i + 1][j][k][news], d[i][j][k][lasts]);
                        }
                        if (news == 1) {
                            d[i][j + 1][k][news] = sum(d[i][j + 1][k][news], d[i][j][k][lasts]);
                        }
                        if (news == 2) {
                            d[i][j][k + 1][news] = sum(d[i][j][k + 1][news], d[i][j][k][lasts]);
                        }
                    }
                    //cerr << i << ' ' << j << ' ' << k << ' ' << lasts << ' ' << d[i][j][k][lasts] << endl;
                }
                d[i][j][k][3] = mul(sum(d[i][j][k][0], sum(d[i][j][k][1], d[i][j][k][2])), mul(mul(fact[i], fact[j]), fact[k]));
            }
        }
    }
    //cerr << "sosatloh\n";
    int ans = 0;
    for (int type = 0; type < 3; type++) {
        dnew[type][0][0] = 1;
        for (int i = 0; i < counts[type]; i++) {
            for (int j = counts[type] - 1; j >= 0; j--) {
                for (int k = t - 1; k >= 0; k--) {
                    if (k + a[type][i] <= t) {
                        dnew[type][j + 1][k + a[type][i]] = sum(dnew[type][j + 1][k + a[type][i]], dnew[type][j][k]);
                    }
                }
            }
        }/*
        for (int i = 0; i <= counts[type]; i++){
            for (int j = 0; j <= t; j++){
                cerr << dnew[type][i][j] << ' ';
            }
            cerr << endl;
        }
        cerr << "lllllllll\n";
        */
    }
    //cerr << "sosatloh\n";
    for (int i = 0; i <= counts[0]; i++) {
        for (int j = 0; j <= counts[1]; j++) {
            fill(dsum, dsum + t + 1, 0);
            for (int news = 0; news <= t; news++) {
                for (int mews = 0; mews <= news; mews++) {
                    dsum[news] = sum1(dsum[news], dnew[0][i][mews] * dnew[1][j][news - mews]);
                }
                dsum[news] %= MOD;
            }
            /*cerr << i << ' ' << j << '\n';
            for (int i = 0; i <= t; i++){
                cerr << dsum[i] << ' ';
            }
            cerr << "\nlllllllll\n";*/
            for (int k = 0; k <= counts[2]; k++) {
                for (int news = 0; news <= t; news++) {
                    //cerr << i << ' ' << j << ' ' << k << ' ' << mul(d[i][j][k][3], mul(dsum[news], dnew[2][k][t - news])) << '\n';
                    ans = sum(ans, mul(d[i][j][k][3], mul(dsum[news], dnew[2][k][t - news])));
                }
            }
        }
    }
    cout << ans;
}