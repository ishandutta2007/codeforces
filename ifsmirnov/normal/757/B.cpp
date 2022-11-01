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

const int maxn = 100500;

int n;
int cnt[maxn];

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    cin >> n;
    forn(III, n) {
        int x;
        cin >> x;
        for (int i = 1; i*i <= x; ++i) {
            if (x%i == 0) {
                ++cnt[i];
                if (i*i != x) ++cnt[x/i];
            }
        }
    }
    cout << max(1, *max_element(cnt+2, cnt+maxn)) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}