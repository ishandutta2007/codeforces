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

    vector<int> out;
    for (int i = 1; i <= 100000; i++) {
        if (i % 3 == 0) continue;
        if (i % 10 == 3) continue;
        out.pb(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << out[n-1] << endl;
    }
}