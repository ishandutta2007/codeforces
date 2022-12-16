#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
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
        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int numneighbors = 4;
                if (j == 0) numneighbors--;
                if (j == m-1) numneighbors--;
                if (i == 0) numneighbors--;
                if (i == n-1) numneighbors--;

                int x;
                cin >> x;
                if (x > numneighbors) good = false;
            }
        }

        if (good) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int numneighbors = 4;
                    if (j == 0) numneighbors--;
                    if (j == m-1) numneighbors--;
                    if (i == 0) numneighbors--;
                    if (i == n-1) numneighbors--;
                    cout << numneighbors << ' ';
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}