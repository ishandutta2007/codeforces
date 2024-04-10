#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long mina, maxa;

long long nod(long long a, long long b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

void pruf(long long n, long long k, long long s) {
    long long x = (n * k) / nod(n * k, s);
    mina = min(mina, x);
    maxa = max(maxa, x);
}

void solve(long long n, long long k, int s, int b) {
    for (long long i = 0; i < n; ++i) {
        long long x = i * k + b + 1;
        if (x == s)
            pruf(n, k, n * k);
        else
            pruf(n, k, (x - s + n * k) % (n * k));
        x = i * k + k - b + 1;
        if (x == s)
            pruf(n, k, n * k);
        else
            pruf(n, k, (x - s + n * k) % (n * k));
    }
}

int main() {
    long long n, k, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> a >> b;
    mina = 1e12 + 1, maxa = 0;
    solve(n, k, a + 1, b);
    solve(n, k, k - a + 1, b);
    cout << mina << ' ' << maxa << endl;
}