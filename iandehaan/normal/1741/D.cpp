#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 300'010

int n;
int p[MAXN];

int canSort(int x, int y) {
    if (x == y) return 0;
    int mylen = y-x+1;
    int halfway = x + (mylen/2);
    // [x, halfway-1]
    // [halfway, y]

    vector<pii> elmts;
    for (int i = x; i <= y; i++) elmts.pb(mp(p[i], i));
    sort(all(elmts));
    int smallpos = elmts[0].second;
    bool ok = true;
    for (int i = 0; i < sz(elmts)/2; i++) {
        int pos = elmts[i].second;
        if (smallpos <= halfway-1) {
            if (pos > halfway-1) {
                ok = false;
            }
        } else {
            if (pos <= halfway-1) ok = false;
        }
    }

    if (!ok) return MAXN;

    int rec1 = canSort(x, halfway-1);
    int rec2 = canSort(halfway, y);
    if (rec1 >= MAXN || rec2 >= MAXN) return MAXN;

    int out = rec1 + rec2;
    if (smallpos > halfway-1) out++;
    return out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> p[i];
            p[i]--;
        }

        int out = canSort(0, n-1);
        if (out >= MAXN) cout << -1 << '\n';
        else cout << out << '\n';
    }
}