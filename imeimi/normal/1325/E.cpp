#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
int A[100001];
int d[1000001];
vector<int> edge[1000001];
int dist[1000001];
int par[1000001];

int solve(int s) {
    vector<int> E;
    queue<int> q;
    par[s] = 0;
    dist[s] = 0;
    E.push_back(s);
    q.push(s);
    int ans = 2e9;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i : edge[x]) {
            if (dist[i] == -1) {
                par[i] = x;
                dist[i] = dist[x] + 1;
                E.push_back(i);
                q.push(i);
            }
            else if (par[x] != i) {
                ans = min(ans, dist[x] + dist[i] + 1);
            }
        }
    }
    for (int i : E) dist[i] = -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    for (int i = 2; i <= 1000000; ++i) {
        if (d[i]) continue;
        for (int j = i; j <= 1000000; j += i) {
            d[j] = i;
        }
    }
    set<int> num;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        set<int> divisor;
        for (int j = A[i]; j > 1; j /= d[j]) {
            if (divisor.count(d[j])) divisor.erase(d[j]);
            else divisor.insert(d[j]);
        }
        if (divisor.empty()) {
            printf("1\n");
            return 0;
        }
        int V[2];
        for (int j = 0; j < 2; ++j) {
            V[j] = divisor.empty() ? 1 : *divisor.begin();
            if (!divisor.empty()) divisor.erase(divisor.begin());
        }
        edge[V[0]].push_back(V[1]);
        edge[V[1]].push_back(V[0]);
    }
    int ans = 2e9;
    for (int i = 1; i <= 1000000; ++i) {
        dist[i] = -1;
    }
    for (int i = 1; i <= 1000; ++i) {
        ans = min(ans, solve(i));
    }
    if (ans > 1e9) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}