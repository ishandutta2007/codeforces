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
        if (n == 3) {
            cout << "-1\n";
            continue;
        }

        if (n % 2 == 0) {
            for (int i = n; i >= 1; i--) cout << i << ' ';
            cout << '\n';
        } else {
            cout << n << ' ' << n-1 << ' ';
            for (int i = 1; i <= n-2; i++) cout << i << ' ';
            cout << '\n';
        }
    }
}