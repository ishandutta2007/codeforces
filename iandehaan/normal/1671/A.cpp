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
        string s;
        cin >> s;
        char prev = 'c';
        int run = 100;
        string out = "YES";
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == prev) run++;
            else {
                if (run < 2) out = "NO";
                run = 1;
            }
            prev = s[i];
        }
        if (run < 2) out = "NO";
        cout << out << endl;
    }
}