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
        char a[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

        char out[n][m];
        for (int j = 0; j < m; j++) {
            int numrocks = 0;
            for (int i = 0; i < n; i++) {
                out[i][j] = '.';
                if (a[i][j] == '*') numrocks++;
                if (a[i][j] == 'o') {
                    out[i][j] = 'o';
                    for (int i2 = i-1; i2 >= 0; i2--) {
                        if (numrocks == 0) break;
                        out[i2][j] = '*';
                        numrocks--;
                        
                    }
                }
            }
            for (int i2 = n-1; i2 >= 0; i2--) {
                if (numrocks == 0) break;
                out[i2][j] = '*';
                numrocks--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << out[i][j];
                
            }
            cout << endl;
        }
        cout << endl;
    }
}