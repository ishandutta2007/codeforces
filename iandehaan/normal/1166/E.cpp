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

    int m, n;
    cin >> m >> n;

    unordered_set<int> a[m];
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int x;
            cin >> x;
            a[i].insert(x);
        }
    }

    bool good = true;

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            bool inter = false;
            for (int x : a[i]) {
                if (a[j].count(x) != 0) {
                    inter = true;
                    break;
                }
            }
            if (!inter) {
                good = false;
                break;
            }
        }
    }

    if (good) cout << "possible" << endl;
    else cout << "impossible" << endl;
}