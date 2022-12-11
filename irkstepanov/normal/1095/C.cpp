#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (n < k) {
        cout << "NO\n";
        return 0;
    }

    vector<int> vals;
    int deg = 1;
    while (n) {
        if (n & 1) {
            vals.pb(deg);
        }
        deg *= 2;
        n >>= 1;
    }

    if (sz(vals) > k) {
        cout << "NO\n";
        return 0;
    }

    int ones = 0;
    queue<int> q;
    for (int x : vals) {
        if (x == 1) {
            ++ones;
        } else {
            q.push(x);
        }
    }

    int curr = sz(vals);
    while (curr < k) {
        int x = q.front();
        q.pop();
        if (x == 2) {
            ones += 2;
            ++curr;
            continue;
        }
        q.push(x / 2);
        q.push(x / 2);
        ++curr;
    }

    cout << "YES\n";
    while (ones--) {
        cout << "1 ";
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
    }
    cout << "\n";

}