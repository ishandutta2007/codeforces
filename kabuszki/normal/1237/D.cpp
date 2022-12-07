#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

int mini(const VI& dp, int pocz, int kon) {
    int M = SIZE(dp) / 2;
    pocz += M;
    kon += M;
    int res = min(dp[pocz], dp[kon]);
    while (pocz / 2 != kon / 2) {
        if (pocz % 2 == 0) res = min(res, dp[pocz + 1]);
        if (kon % 2 == 1) res = min(res, dp[kon - 1]);
        pocz /= 2;
        kon /= 2;
    }
    return res;
}

VI zbuduj_drzewo(const VI& v) {
    int M = 1;
    while (M < SIZE(v)) M *= 2;
    VI dp(2 * M);
    REP(i, SIZE(v)) dp[M + i] = v[i];
    FORD(i, M - 1, 0) dp[i] = min(dp[2 * i], dp[2 * i + 1]);
    return dp;
}

void jebaj() {
    int n;
    cin >> n;
    int N = 3 * n;
    VI v(N), dupa(N);
    REP(i, n) cin >> v[i];
    FOR(i, n, N - 1) v[i] = v[i - n];
    set<PII> secik;
    FORD(i, N - 1, 0) {
        int val = (v[i] - 1) / 2;
        auto it = secik.lower_bound({val, 1333337});
        if (it == secik.begin()) {
            dupa[i] = N;
        } else {
            it--;

            dupa[i] = it->second;
        }
        while (true) {
            if (secik.empty()) break;
            auto it2 = secik.end();
            it2--;
            if (it2->first >= v[i]) {
                secik.erase(it2);
            } else {
                break;
            }
        }
        secik.insert({v[i], i});
    }

    auto dp = zbuduj_drzewo(dupa);
    if (mini(dp, 0, n - 1) == N) {
        REP(i, n) cout << "-1 ";
        cout << "\n";
        return;
    }

    //REP(i, N) cerr << dupa[i] << " "; cerr << "\n";

    REP(i, n) {
        int pocz = i, kon = N;
        while (pocz + 1 < kon) {
            int mid = (pocz + kon) / 2;
            if (mini(dp, i, mid) <= mid) kon = mid;
            else pocz = mid;
        }
        cout << pocz - i + 1 << " ";
    }
    cout << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    //cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}