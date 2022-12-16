#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

        set<int> poss;
        int cr = 0;
        for (int i = 0; i < n; i++) {
            cr ^= a[i];
            poss.insert(cr);
        }

        bool found = false;
        for (int trythis : poss) {
            int curr = 0;
            int numresets = 0;
            for (int i = 0; i < n; i++) {
                curr ^= a[i];
                if (curr == trythis) {
                    curr = 0;
                    numresets++;
                }
                //if (trythis == 10) cout << i << ' ' << curr << endl;
            }
            if (curr == 0 && numresets > 1) {
                //cout << trythis << endl;
                found = true;
                break;
            }
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}