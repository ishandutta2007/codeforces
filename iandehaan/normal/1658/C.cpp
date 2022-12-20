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
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        //cout << n << endl;
        bool good = true;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i-1] && (a[i] != a[i-1]+1)) good = false;
        }

        if (a[0] > a[n-1] && (a[0] != a[n-1]+1)) good = false;

        int numones = 0;
        bool existstwo = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) numones++;
            if (a[i] == 2) existstwo = true;
        }

        if (numones != 1) good = false;
        if (!existstwo) good = false;

        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}