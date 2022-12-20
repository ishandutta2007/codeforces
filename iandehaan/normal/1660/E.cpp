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
        char a[n][n];
        int numones = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') numones++;
        }

        int mxdiag = 0;

        for (int strt = 0; strt < n; strt++) {
            int i = strt;
            int j = 0;
            int med = 0;
            for (int k = 0; k < n; k++) {
                if (a[i][j] == '1') med++;

                i++;
                j++;
                i %= n;
            }
            mxdiag = max(mxdiag, med);
        }

        //cout << "here " << n << endl;

        int out = (n-mxdiag) + (numones-mxdiag);
        cout << out << '\n';
    }
}