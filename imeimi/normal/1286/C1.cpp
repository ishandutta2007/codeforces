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
int P[101];
vector<pii> edge[101];
int A[101];

void add_edge(int x, int y, int w) {
    edge[x].emplace_back(y, w);
    edge[y].emplace_back(x, w);
}

void check(int n) {
    printf("? 1 %d\n", n);
    fflush(stdout);
    int v[105] = {};
    for (int i = 1; i <= n * (n + 1) / 2; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            v[s.length()] += c;
        }
    }
    if (n == 1) A[1] = v[1];
    for (int i = n; n - i + 1 < i; --i) {
        add_edge(i, n - i + 1, (v[i] - v[i + 1]) - (v[i - 1] - v[i]));
    }
}

void dfs(int x) {
    for (pii i : edge[x]) {
        if (A[i.fs]) continue;
        A[i.fs] = i.se - A[x];
        dfs(i.fs);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    check(n);
    if (n > 2) check(n - 1);
    check(1);
    for (int i = 1; i <= n; ++i) {
        if (A[i] == 0) continue;
        dfs(i);
        break;
    }
    printf("! ");
    for (int i = 1; i <= n; ++i) {
        printf("%c", (char)A[i]);
    }
    printf("\n");
    return 0;
}