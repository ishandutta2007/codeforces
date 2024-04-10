#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

vi lis(vi arg) {
    vi res, table = { -1 };
    for (int v : arg) {
        auto it = upper_bound(all(table), v);
        if (it == table.end()) {
            table.push_back(v);
        } else {
            table[it - table.begin()] = v;
        }
        res.push_back(table.size() - 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<array<int, 2>> events;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        events.push_back({ a, 1 });
        events.push_back({ b + 1, -1 });
    }

    sort(all(events));

    vi ct(M);
    int cur = 0, j = 0;
    for (int i = 0; i < M; i++) {
        while (j < events.size() && events[j][0] == i)
            cur += events[j++][1];
        ct[i] = cur;
    }

    WATCHC(ct);

    vi lisF = lis(ct);
    reverse(all(ct));
    vi lisB = lis(ct);
    reverse(all(lisB));

    WATCHC(lisF);
    WATCHC(lisB);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans = max(ans, (i ? lisF[i-1] : 0) + lisB[i]);
    }
    cout << ans << endl;

    return 0;
}