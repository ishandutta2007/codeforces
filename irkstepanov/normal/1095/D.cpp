#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 3) {
        cout << "1 2 3\n";
        return 0;
    }

    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[i] = {x, y};
    }

    int curr = 0;

    for (int i = 0; i < n; ++i) {
        cout << curr + 1 << " ";
        if (i == n - 1) {
            break;
        }
        int to = g[curr][0];
        if (g[to][0] == g[curr][1] || g[to][1] == g[curr][1]) {
            curr = to;
        } else {
            curr = g[curr][1];
        }
    }
    cout << "\n";

}