#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector <vector <int> > a(n, vector <int> (m));
    rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
    pair <int, int> ans;
    rep(j, m) {
        int cost = 0;
        pair <int, int> mx(0, 0);
        rep(i, n) {
            if (a[i][j]) {
                int s = 0;
                for (int x = 0; x < k && i + x < n; ++ x)
                    s += a[i + x][j];
                mx = max(mx, mp(s, -cost));
                ++ cost;
            }
        }
        ans.first += mx.first;
        ans.second += mx.second;
    }
    printf("%d %d\n", ans.first, -ans.second);
    return 0;
}