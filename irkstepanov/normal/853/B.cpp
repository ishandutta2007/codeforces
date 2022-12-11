#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll inf = 1e18;

struct data {
    int city;
    ll cost;
};

const int dmax = 1e6 + 100;

ll suff[dmax];
ll pref[dmax];
vector<data> from[dmax];
vector<data> to[dmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int day, a, b;
        ll cost;
        cin >> day >> a >> b >> cost;
        if (a == 0 && b == 0) {
            continue;
        }
        if (a == 0) {
            from[day].pb({b, cost});
        } else if (b == 0) {
            to[day].pb({a, cost});
        }
    }

    vector<ll> bestCost(n + 1, inf);
    ll sum;
    int cntInf = n;

    for (int d = dmax - 1; d >= 0; --d) {
        if (d + 1 < dmax) {
            for (data& q : from[d + 1]) {
                int id = q.city;
                if (bestCost[id] == inf) {
                    --cntInf;
                    bestCost[id] = q.cost;
                    if (cntInf == 0) {
                        sum = 0;
                        for (int i = 1; i <= n; ++i) {
                            sum += bestCost[i];
                        }
                    }
                } else if (bestCost[id] > q.cost) {
                    if (cntInf == 0) {
                        sum -= bestCost[id];
                        sum += q.cost;
                    }
                    bestCost[id] = q.cost;
                }
            }
        }
        if (cntInf == 0) {
            suff[d] = sum;
        } else {
            suff[d] = inf;
        }
    }

    bestCost.assign(n + 1, inf);
    cntInf = n;
    for (int d = 1; d < dmax; ++d) {
        if (d - 1 >= 1) {
            for (data& q : to[d - 1]) {
                int id = q.city;
                if (bestCost[id] == inf) {
                    --cntInf;
                    bestCost[id] = q.cost;
                    if (cntInf == 0) {
                        sum = 0;
                        for (int i = 1; i <= n; ++i) {
                            sum += bestCost[i];
                        }
                    }
                } else if (bestCost[id] > q.cost) {
                    if (cntInf == 0) {
                        sum -= bestCost[id];
                        sum += q.cost;
                    }
                    bestCost[id] = q.cost;
                }
            }
        }
        if (cntInf == 0) {
            pref[d] = sum;
        } else {
            pref[d] = inf;
        }
    }

    ll ans = inf;

    for (int d = 1; d + k - 1 < dmax; ++d) {
        ans = min(ans, pref[d] + suff[d + k - 1]);
    }
    cout << (ans == inf ? -1 : ans) << "\n";

}