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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

        int speci = -1;
        int specj = -1;
        rep(i, 0, n) {
            int largest = a[i][0];
            rep(j, 0, m) {
                largest = max(largest, a[i][j]);
                if (largest > a[i][j]) {
                    speci = i;
                    specj = j;
                }
            }
        }

        //cout << speci << ' ' << specj << endl;

        if (speci == -1) {
            cout << "1 1" << '\n';
            continue;
        }

        int swap1 = 0;
        int swap2 = specj;

        rep(j, 0, m) {
            if (a[speci][j] > a[speci][specj]) {
                swap1 = j;
                break;
            }
        }
        rep(i, 0, n) {
            swap(a[i][swap1], a[i][swap2]);
        }

        bool ok = true;
        rep(i, 0, n) {
            rep(j, 0, m-1) {
                if (a[i][j] > a[i][j+1]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << swap1+1 << ' ' << swap2+1 << '\n';
        } else {
            cout << -1 << '\n';
        }

        
    }
}