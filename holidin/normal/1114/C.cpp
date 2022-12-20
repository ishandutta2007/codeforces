#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
const long long inf = 4e18 + 1;

vector <pair<int, int> > v;
int a[N], c[N];


long long rf(long long x, long long n) {
    long long c = x, ans = 0;
    while (c <= n) {
        ans += n / c;
        if (c <= (2 * n) / x + 4)
            c *= x;
        else
            break;
    }
    return ans;
}

int main() {
    int i, j, m, k;
    long long n, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> b;
    long long cnt = inf;
    for (long long x = 2; x * x <= b; ++x)
    if (b % x == 0) {
        int ct = 0;
        while (b % x == 0) {
            ++ct;
            b /= x;
        }
        cnt = min(cnt, rf(x, n) / ct);
    }
    if (b > 1)
        cnt = min(cnt, rf(b, n));
    cout << cnt;
}