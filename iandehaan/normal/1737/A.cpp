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
        string s;
        cin >> s;
        int cnts[300];
        rep(i, 0, 300) cnts[i] = 0;
        rep(i, 0, n) {
            cnts[s[i]-'a']++;
        }

        string out;

        rep(i, 0, k) {
            rep(j, 0, n/k) {
                cnts[j]--;
                if (cnts[j] < 0) {
                    out.pb('a'+j);
                    break;
                }
            }

            if (sz(out) < i+1) {
                out.pb('a'+(n/k));
            }
        }
        cout << out << endl;
    }
}