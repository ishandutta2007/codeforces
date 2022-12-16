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
        int out = 0;
        for (int i = n-2; i >= 0; i--) {
            while (a[i] >= a[i+1]) {
                if (a[i] == 0) {
                    out = -1;
                    break;
                }
                out++;
                a[i] /= 2;
            }
            if (out == -1) break;
        }
        cout << out << endl;
    }
}