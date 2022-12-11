#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

const int nmax = 100500;
const int tmax = 201;

int a[nmax];
int dp[2][2][tmax];

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //memset(dp, 0, sizeof(dp));
    int ptr = 0;
    if (a[0] == -1) {
        for (int x = 1; x < tmax; ++x) {
            dp[0][0][x] = 1;
        }
    } else {
        dp[0][0][a[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        memset(dp[ptr ^ 1], 0, sizeof(dp[ptr ^ 1]));
        int sumrg = 0;
        for (int x = 1; x < tmax; ++x) {
            add(sumrg, dp[ptr][1][x]);
        }
        int sumlf = 0;
        int sum = 0;
        for (int x = 1; x < tmax; ++x) {
            //add(sum, dp[ptr][0][x]);
            sub(sumrg, dp[ptr][1][x]);
            if (x) {
                add(sumlf, dp[ptr][1][x - 1]);
                add(sum, dp[ptr][0][x - 1]);
            }
            if (a[i] != -1 && a[i] != x) {
                continue;
            }
            add(dp[ptr ^ 1][1][x], sumrg);
            add(dp[ptr ^ 1][0][x], sumlf);
            add(dp[ptr ^ 1][1][x], dp[ptr][1][x]);
            add(dp[ptr ^ 1][0][x], sum);
            add(dp[ptr ^ 1][1][x], dp[ptr][0][x]);
        }
        ptr ^= 1;
    }

    int ans = 0;
    for (int x = 1; x < tmax; ++x) {
        add(ans, dp[ptr][1][x]);
    }
    cout << ans << "\n";

}