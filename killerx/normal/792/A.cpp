#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int mn = 2e9 + 7, cnt = 0;
    rep(i, n - 1) {
        int x = a[i + 1] - a[i];
        if (x < mn) mn = x, cnt = 0;
        if (x == mn) ++ cnt;
    }
    printf("%d %d\n", mn, cnt);
    return 0;
}