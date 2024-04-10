#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, T;
    cin >> N >> T;

    vector<vector<pair<int, int>>> prob(N + 1);
    for (int i = 0; i < N; i++) {
        int a, t;
        cin >> a >> t;
        prob[a].push_back(make_pair(t, i));
    }

    ll total = 0;
    priority_queue<pair<int, int>> solve;

    for (int sc = N; sc >= 0; sc--) {
        for (auto p : prob[sc]) {
            total += p.first;
            solve.push(p);
        }

        while (solve.size() > sc) {
            auto d = solve.top();
            total -= d.first;
            solve.pop();
        }

        if (solve.size() == sc && total <= T) {
            cout << sc << "\n" << sc << "\n";
            while (!solve.empty()) {
                cout << solve.top().second + 1 << " ";
                solve.pop();
            }
            cout << endl;
            return 0;
        }
    }

    return 0;
}