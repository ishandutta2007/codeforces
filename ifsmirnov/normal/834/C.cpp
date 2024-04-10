#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

int rt(i64 x) {
    int t = round(cbrt(x));
    if (1ll*t*t*t == x) {
        return t;
    }
    return -1;
}

void yes() {
    cout << "YES\n";
}

void no() {
    cout << "NO\n";
}


int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // scanf("%d", &t);
    for (int III = 0; III < t; ++III) {
        int a, b;
        cin >> a >> b;
        int t = rt((i64)a*b);
        if (t != -1 && a%t == 0 && b%t == 0) yes();
        else no();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}