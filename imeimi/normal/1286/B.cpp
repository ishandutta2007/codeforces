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
int P[2001], C[2001];
int A[2001];
vector<int> child[2001];

void fail() {
    printf("NO\n");
    exit(0);
}

vector<int> dfs(int x) {
    vector<int> ret;
    for (int i : child[x]) {
        vector<int> c = dfs(i);
        for (int j : c) ret.push_back(j);
    }
    sort(ret.begin(), ret.end(), [&](int a, int b) {
        return A[a] < A[b];
    });
    if ((int)ret.size() < C[x]) fail();
    int v = C[x] ? A[ret[C[x] - 1]] + 1 : 1;
    for (int i = 1; i <= n; ++i) {
        if (v <= A[i]) ++A[i];
    }
    A[x] = v;
    ret.push_back(x);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    int r = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i] >> C[i];
        if (P[i] == 0) r = i;
        else {
            child[P[i]].push_back(i);
        }
    }
    dfs(r);
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%d ", A[i]);
    return 0;
}