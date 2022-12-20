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
        unordered_set<int> stuff;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            stuff.insert(a[i]);
        }
        bool found = false;

        for (int i = 0; i < n; i++) {
            int needed = a[i] - k;
            if (stuff.count(needed) != 0) {
                found = true;
                break;
            }
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
}