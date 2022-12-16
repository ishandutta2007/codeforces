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
        for (int i = 0; i < n; i++) cin >> a[i];

        bool containsk = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == k) containsk = true;
        }

        if (!containsk) {
            cout << "no" << endl;
            continue;
        }

        bool good[n];
        for (int i = 0; i < n; i++) {
            if (a[i] >= k) good[i] = true;
            else good[i] = false;
        }

        for (int i = 0; i+2 < n; i++) {
            if (good[i] && good[i+1]) good[i+2] = true;
            if (good[i] && good[i+2]) good[i+1] = true;
        }

        for (int i = n-1; i-2 >= 0; i--) {
            if (good[i] && good[i-1]) good[i-2] = true;
            if (good[i] && good[i-2]) good[i-1] = true;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (good[i]) cnt++;
        }

        if (cnt > n/2) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}