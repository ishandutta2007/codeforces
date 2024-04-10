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

int getCnt(string& s, char c) {
    int out = 0;
    for (char d : s) if (d == c) out++;
    return out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        bool poss = true;
        // counts must be the same
        if (getCnt(s, 'a') != getCnt(t, 'a') || getCnt(s, 'b') != getCnt(t, 'b') || getCnt(s, 'c') != getCnt(t, 'c')) poss = false;

        int need[3];
        need[0] = 0;
        need[1] = 0;
        need[2] = 0;

        rep(i, 0, n) {
            if (need[0] != 0) {
                // need to move an a back... impossible
                poss = false;
            } else if (need[1] != 0) {
                // need to move a b back...
                if (s[i] == 'c') poss = false;
                if (s[i] == 'b') {
                    need[1]--;
                    s[i] = 'a';
                }
            } else if (need[2] != 0) {
                // need to move a c back
                if (s[i] == 'a') poss = false;
                if (s[i] == 'c') {
                    need[2]--;
                    s[i] = 'b';
                }
            }

            if (!poss) break;

            if (s[i] == t[i]) continue;

            need[t[i]-'a']++;

            if (need[0] != 0) {
                poss = false;
            }
            if (need[1] != 0) {
                if (s[i] == 'c') poss = false;
            }
            if (need[2] != 0) {
                if (s[i] == 'a') poss = false;
            }

            if (!poss) break;


        }


        if (poss) cout << "YES\n";
        else cout << "NO\n";


    }
}