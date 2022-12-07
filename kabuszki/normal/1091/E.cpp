#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back

#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

void jebaj() {
    int n;
    cin >> n;
    VI v(n);
    REP(i, n) cin >> v[i];
    int s = 0;
    for (int a : v) s += a;

    sort(ALL(v));
    reverse(ALL(v));
    VI rowne(n + 1), wieksze(n + 1);
    for (int a : v) rowne[a]++;
    FORD(i, n - 1, 0) wieksze[i] = wieksze[i + 1] + rowne[i + 1];
    VI prefsum(n), sufsum(n + 1);
    prefsum[0] = v[0];
    FOR(i, 1, n - 1) prefsum[i] = prefsum[i - 1] + v[i];
    FORD(i, n - 1, 0) sufsum[i] = sufsum[i + 1] + v[i];

    VII ineqs;

    FOR(k, 1, n) {

        int L = prefsum[k - 1];
        int wrowne = wieksze[k] + rowne[k];
        int mniejsze = n - wrowne;
        if (mniejsze > n - k) mniejsze = n - k;
        int R = k * (k - 1) + sufsum[n - mniejsze] + k * (n - k - mniejsze);
               // cerr << k << " " << L << " " << R << "\n";

        if (L - k > R) {
            cout << "-1\n";
            return;
        }

        int geq = max(L - R, 0ll);

        int r = rowne[k];
        if (r + mniejsze > n - k) r = n - k - mniejsze;

        int x = min(R - L + k, mniejsze + r);
        int leq = k + x + (n - k - mniejsze - r);

        ineqs.EB(geq, leq);
    }
   // cerr << "\n";

    //for (auto p : ineqs) cerr << p.ST << " " << p.ND << "\n";

    int max_left = 0;
    for (auto  p : ineqs) max_left = max(max_left, p.ST);
    int min_right = n + n;
    for (auto  p : ineqs) min_right = min(min_right, p.ND);

    //cerr << max_left << " " << min_right << "\n";

    if (max_left % 2 != s % 2) max_left++;
    VI res;
    for (int i = max_left; i <= min_right; i += 2) res.PB(i);
    if (res.empty()) {
        cout << "-1\n";
        return;
    }
    for (int a : res) cout << a << " "; cout << "\n";
}

#undef int
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}