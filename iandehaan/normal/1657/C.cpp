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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ops = 0;
        int ind = 0;
        while (true) {
            if (ind == n-1) {
                break;
            }

            if (s[ind] == '(') {
                ops++;
                ind += 2;
            } else {
                bool found = false;
                for (int i = ind+1; i < n; i++) {
                    if (s[i] == ')') {
                        ops++;
                        ind = i+1;
                        found = true;
                        break;
                    }
                }
                if (!found) break;
            }
        }

        cout << ops << ' ' << n-ind << '\n';
    }
}