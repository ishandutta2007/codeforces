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
        string inp;
        cin >> inp;
        char firstthing = '?';
        int firstind = -1;
        for (int i = 0; i < n; i++) {
            if (inp[i] != '?') {
                firstthing = inp[i];
                firstind = i;
                break;
            }
        }

        string out;

        for (int i = 0; i < n; i++) {
            if (inp[i] == '?') {
                if (i == 0) {
                    if (firstind == -1) {
                        out.pb('R');
                    } else {
                        if (firstind % 2 == 0) {
                            out.pb(firstthing);
                        } else {
                            if (firstthing == 'B') out.pb('R');
                            else out.pb('B');
                        }
                    }
                } else {
                    if (out[i-1] == 'B') {
                        out.pb('R');
                    } else {
                        out.pb('B');
                    }
                }
            } else {
                out.pb(inp[i]);
            }
        }

        cout << out << endl;
    }
}