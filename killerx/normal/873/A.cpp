#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    vector <int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, n) ans += i >= n - k ? x : a[i];
    printf("%d\n", ans);
    return 0;
}