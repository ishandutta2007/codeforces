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

void check(int s, int e) {
    if (s > e) return;
    int n = e - s + 1;
    printf("? %d %d\n", s, e);
    fflush(stdout);
    int v[105] = {};
    for (int i = 1; i <= n * (n + 1) / 2; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            v[s.length()] += c;
        }
    }
    for (int i = n; n - i + 1 < i; --i) {
        add_edge(s - 1 + i, s - 1 + n - i + 1, (v[i] - v[i + 1]) - (v[i - 1] - v[i]));
    }
    if (n & 1) {
        int i = n + 1 >> 1;
        A[s - 1 + i] = v[i] - v[i + 1];
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
    check(1, n);
    int x = n / 2;
    if (n % 2 == 0) {
        if (x % 2 == 0) --x;
        else if (x != 1) x -= 2;
    }
    check(1, x);
    check(x + 1, n);
    for (int i = 1; i <= n; ++i) {
        if (A[i] == 0) continue;
        dfs(i);
    }
    printf("! ");
    for (int i = 1; i <= n; ++i) {
        printf("%c", (char)A[i]);
    }
    printf("\n");
    return 0;
}