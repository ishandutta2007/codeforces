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
        int n, k;
        cin >> n >> k;
        int a[n];
        int below = 0;
        int above = 0;
        int equal = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] == 1) equal++;
            else if (a[i] < 1) below++;
            else above++;
        }

        if (equal > 0) cout << "YES\n";
        else cout << "NO\n";
    }
}