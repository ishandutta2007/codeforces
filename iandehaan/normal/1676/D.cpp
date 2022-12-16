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
        map<pii, int> val1;
        map<pii, int> val2;
        rep(i, 0, n) {
            int k = i;
            int j = 0;
            int med = 0;
            while (k < n && j < m) {
                med += a[k][j];
                k++;
                j++;
            }
            val1[mp(i, 0)] = med;
        }
        rep(j, 0, m) {
            int k = j;
            int i = 0;
            int med = 0;
            while (k < m && i < n) {
                med += a[i][k];
                k++;
                i++;
            }
            val1[mp(0, j)] = med;
        }

        rep(i, 0, n) {
            int k = i;
            int j = 0;
            int med = 0;
            while (k >= 0 && j < m) {
                med += a[k][j];
                k--;
                j++;
            }
            val2[mp(i, 0)] = med;
        }
        rep(j, 0, m) {
            int k = j;
            int i = n-1;
            int med = 0;
            while (k < m && i >= 0) {
                med += a[i][k];
                k++;
                i--;
            }
            val2[mp(n-1, j)] = med;
        }

        int out = 0;
        rep(i, 0, n) rep(j, 0, m) {
            int mn = min(i, j);
            int ii = i-mn;
            int jj = j-mn;
            int med1 = val1[mp(ii, jj)];
            int med2;
            int disttoleft = j;
            if (disttoleft + i < n) {
                med2 = val2[mp(disttoleft+i, 0)];
            } else {
                int disttobot = (n-1) - i;
                med2 = val2[mp(n-1, j-disttobot)];
            }
            out = max(out, med1+med2-a[i][j]);
        }
        cout << out << endl;
    }
}