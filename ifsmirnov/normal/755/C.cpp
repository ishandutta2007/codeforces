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

const int maxn = 10050;
int n;
int a[maxn];
int b[maxn];

int main() {
#ifdef LOCAL
//     freopen("c.in", "r", stdin);
#endif

    cin >> n;
    forn(i, n) cin >> a[i], --a[i];
    int res = 0;
    forn(i, n) if (!b[i]) {
        ++res;
        int d1 = a[i];
        int d2 = a[a[i]];
        forn(j, n) if (!b[j] && (a[j] == d1 || a[j] == d2)) b[j] = 1;
    }
    cout << res << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}