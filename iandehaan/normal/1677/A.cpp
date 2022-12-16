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
#define MAXN 5010

ll numsmaller[MAXN][MAXN];
int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        rep(i, 0, n) cin >> a[i];
        
        rep(i, 0, n) rep(j, 0, n) {
            numsmaller[i][j] = 0;
        }

        rep(i, 0, n) {
            int cnt2 = 0;
            for (int j = n-1; j >= 0; j--) {
                if (a[j] < a[i]) cnt2++;
                numsmaller[i][j] = cnt2;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                numsmaller[j][i] = numsmaller[j-1][i] + numsmaller[j][i];
            }
        }
        ll out = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+2; j < n-1; j++) {
                // i is a, j is c
                if (a[i] >= a[j]) continue;
                // add numsmaller[i+1][j+1] through numsmaller[j-1][j+1]
                out += numsmaller[j-1][j+1];
                out -= numsmaller[i][j+1];
            }
        }
        cout << out << '\n';
    }
}