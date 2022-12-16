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

        set<int> radj[n];
        vector<int> adj[n];
        int deg[n];
        for (int i = 0; i < n; i++) deg[i] = 0;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                x--;
                radj[i].insert(x);
                adj[x].pb(i);
                deg[i]++;
            }
        }

        int out = 0;
        vector<int> toprocess;
        // todo: fill with all that start as 0
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) toprocess.pb(i);
        }
        while (true) {
            // Check if we finished.
            // Todo: not this. This is slow.
            if (sz(toprocess) == 0) break;

            out++;

            set<int> processnxt;
            map<int, int> biggestclear;
            for (int x : toprocess) {
                deg[x] = -1; // mark it as processed
                for (int nxt : adj[x]) {
                    deg[nxt]--;
                    if (biggestclear.find(nxt) != biggestclear.end()) {
                        biggestclear[nxt] = max(biggestclear[nxt], x);
                    } else {
                        biggestclear[nxt] = x;
                    }
                    if (deg[nxt] == 0) processnxt.insert(nxt);
                }
            }

            toprocess.clear();

            queue<int> processme;
            for (int x : processnxt) processme.push(x);

            while (!processme.empty()) {
                int frnt = processme.front(); processme.pop();

                if (biggestclear[frnt] < frnt) {
                    // we get frnt for free
                    deg[frnt] = -1;

                    for (int nxt : adj[frnt]) {
                        deg[nxt]--;
                        if (biggestclear.find(nxt) != biggestclear.end()) {
                            biggestclear[nxt] = max(biggestclear[nxt], frnt);
                        } else {
                            biggestclear[nxt] = frnt;
                        }
                        if (deg[nxt] == 0 && processnxt.count(nxt) == 0) {
                            processnxt.insert(nxt);
                            processme.push(nxt);
                        }
                    }
                } else {
                    toprocess.pb(frnt);
                }
            }
        }
        bool done = true;
        for (int i = 0; i < n; i++) if (deg[i] != -1) done = false;
        if (!done) out = -1;
        cout << out << endl;
    }
}