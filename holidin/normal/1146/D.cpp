#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 45;

bool use[N];
long long cnt = 0, a, b;

void dfs(int u, int mxn) {
    if (u > mxn || u < 0)
        return;
    if (use[u])
        return;
    use[u] = 1;
    ++cnt;
    dfs(u + a, mxn);
    dfs(u - b, mxn);
}

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}



int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    int c = a;
    while (c < a + b)
        c += a;
    long long ans = 1;
    cnt = 1;
    use[0] = 1;
    for (i = 1; i <= min(n, c); ++i) {
        if (i >= a && use[i - a])
            dfs(i, i);
        ans += cnt;
    }
    if (n > c) {
        n -= c;
        long long pp = nod(a, b);
        long long ct = n / pp;
        ans += cnt * n + pp * ((ct * (ct - 1)) / 2) + ct * (n % pp + 1);
    }
    cout << ans;
}