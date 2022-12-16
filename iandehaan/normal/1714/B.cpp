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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        rep(i, 0, n) cin >> a[i];
        set<int> seen;
        int breaks = -1;
        for (int i = n-1; i >= 0; i--) {
            if (seen.count(a[i])) {
                breaks = i;
                break;
            }
            seen.insert(a[i]);
        }

        cout << breaks+1 << '\n';
    }
}