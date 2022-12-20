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
        map<int, int> cnt;
        int n;
        cin >> n;
        int out = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if (cnt[x] >= 3) out = x;
        }
        cout << out << endl;
    }
}