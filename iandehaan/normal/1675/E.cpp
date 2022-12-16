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

string a;
int n;

char bestmp[26];

void solve(int ind, int k) {
    if (ind >= n) return;
    int charind = a[ind] - 'a';


    while (bestmp[charind] != 'a' && k > 0) {
        k--;
        char toupdate = bestmp[charind];
        for (int i = 0; i < 26; i++) {
            if (bestmp[i] == toupdate) bestmp[i] = bestmp[toupdate-'a'-1];
        }
    }

    cout << bestmp[charind];
    solve(ind+1, k);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        cin >> a;
        for (int i = 0; i < 26; i++) bestmp[i] = 'a'+i;
        solve(0, k);
        cout << endl;
        /*if ((a[0] - 'a') <= k) {
            for (int i = 0; i < n; i++) {
                if (a[i] - 'a' <= k) {
                    cout << 'a';
                } else {
                    cout << a[i];
                }
            }
            cout << '\n';
        } else {
            char mymap = a[0] - k;
            for (int i = 0; i < n; i++) {
                if (a[i] <= mymap) {
                    cout << a[i];
                    continue;
                }
                if (a[i] - mymap <= k) {
                    cout << mymap;
                } else {
                    cout << a[i];
                }
            }
            cout << '\n';
        }*/

    }
}