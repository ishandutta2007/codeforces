#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int lf = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        y += a[i];
        lf = max(lf, a[i]);
    }
    --lf;

    int rg = 1e7;
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        int x = md * n - y;
        if (x > y) {
            rg = md;
        } else {
            lf = md;
        }
    }

    cout << rg << "\n";

}